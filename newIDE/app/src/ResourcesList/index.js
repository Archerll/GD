// @flow
import * as React from 'react';
import { AutoSizer } from 'react-virtualized';
import SortableVirtualizedItemList from '../UI/SortableVirtualizedItemList';
import Paper from 'material-ui/Paper';
import SearchBar from 'material-ui-search-bar';
import { showWarningBox } from '../UI/Messages/MessageBox';
import { filterResourcesList } from './EnumerateResources';

const styles = {
  container: {
    flex: 1,
    display: 'flex',
    height: '100%',
    flexDirection: 'column',
  },
  listContainer: {
    flex: 1,
  },
};

type State = {|
  renamedResource: ?gdResource,
  searchText: string,
|};

type Props = {|
  project: gdProject,
  selectedResource: ?gdResource,
  onSelectResource: (resource: gdResource) => void,
  onDeleteResource: (resource: gdResource) => void,
  onRenameResource: (
    resource: gdResource,
    newName: string,
    cb: (boolean) => void
  ) => void,
|};

export default class ResourcesList extends React.Component<Props, State> {
  static defaultProps = {
    onDeleteResource: (resource: gdResource, cb: boolean => void) => cb(true),
    onRenameResource: (
      resource: gdResource,
      newName: string,
      cb: boolean => void
    ) => cb(true),
  };

  sortableList: any;
  state: State = {
    renamedResource: null,
    searchText: '',
  };

  shouldComponentUpdate(nextProps: Props, nextState: State) {
    // The component is costly to render, so avoid any re-rendering as much
    // as possible.
    // We make the assumption that no changes to resources list is made outside
    // from the component.
    // If a change is made, the component won't notice it: you have to manually
    // call forceUpdate.

    if (
      this.state.renamedResource !== nextState.renamedResource ||
      this.state.searchText !== nextState.searchText
    )
      return true;

    if (
      this.props.project !== nextProps.project ||
      this.props.selectedResource !== nextProps.selectedResource
    )
      return true;

    return false;
  }

  _deleteResource = (resource: gdResource) => {
    this.props.onDeleteResource(resource);
  };

  _editName = (resource: ?gdResource) => {
    this.setState(
      {
        renamedResource: resource,
      },
      () => this.sortableList.getWrappedInstance().forceUpdateGrid()
    );
  };

  _rename = (resource: gdResource, newName: string) => {
    const { project } = this.props;
    this.setState({
      renamedResource: null,
    });

    if (resource.getName() === newName) return;

    if (project.getResourcesManager().hasResource(newName)) {
      showWarningBox('Another resource with this name already exists');
      return;
    }

    this.props.onRenameResource(resource, newName, doRename => {
      if (!doRename) return;
      resource.setName(newName);
      this.forceUpdate();
    });
  };

  _move = (oldIndex: number, newIndex: number) => {
    const { project } = this.props;

    project.getResourcesManager().moveResource(oldIndex, newIndex);
    this.forceUpdateList();
  };

  forceUpdateList = () => {
    this.forceUpdate();
    this.sortableList.getWrappedInstance().forceUpdateGrid();
  };

  _renderResourceMenuTemplate = (resource: gdResource) => {
    return [
      {
        label: 'Rename',
        click: () => this._editName(resource),
      },
      {
        label: 'Delete',
        click: () => this._deleteResource(resource),
      },
    ];
  };

  render() {
    const { project, selectedResource, onSelectResource } = this.props;
    const { searchText } = this.state;

    const resourcesManager = project.getResourcesManager();
    const allResourcesList = resourcesManager
      .getAllResourceNames()
      .toJSArray()
      .map(resourceName => resourcesManager.getResource(resourceName));
    const filteredList = filterResourcesList(allResourcesList, searchText);

    // Force List component to be mounted again if project or objectsContainer
    // has been changed. Avoid accessing to invalid objects that could
    // crash the app.
    const listKey = project.ptr;

    return (
      <Paper style={styles.container}>
        <div style={styles.listContainer}>
          <AutoSizer>
            {({ height, width }) => (
              <SortableVirtualizedItemList
                key={listKey}
                ref={sortableList => (this.sortableList = sortableList)}
                fullList={filteredList}
                width={width}
                height={height}
                selectedItem={selectedResource}
                onItemSelected={onSelectResource}
                renamedItem={this.state.renamedResource}
                onRename={this._rename}
                onSortEnd={({ oldIndex, newIndex }) =>
                  this._move(oldIndex, newIndex)}
                helperClass="sortable-helper"
                distance={30}
                buildMenuTemplate={this._renderResourceMenuTemplate}
              />
            )}
          </AutoSizer>
        </div>
        <SearchBar
          value={searchText}
          onRequestSearch={() => {}}
          onChange={text =>
            this.setState({
              searchText: text,
            })}
        />
      </Paper>
    );
  }
}
