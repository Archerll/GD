import React, { Component } from 'react';
import FlatButton from 'material-ui/FlatButton';
import Dialog from '../UI/Dialog';
import ListIcon from '../UI/ListIcon';
import { List, ListItem, makeSelectable } from 'material-ui/List';
const SelectableList = makeSelectable(List);
const gd = global.gd;

const styles = {
  icon: { borderRadius: 0 },
  explanations: {
    textAlign: 'center',
    margin: 20,
  },
};

const publicImageUrls = [
  // Platformer images (see platformer.json in fixtures)
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_stand.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_jump.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk01.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk02.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk03.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk04.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk05.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk06.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk07.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk08.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk09.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk10.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/p1_walk11.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/brickWall.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/bridge.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/grassHalfMid.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/castleCenter.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/bridgeLogs.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/Left.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/Right.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/ladder_mid.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/Grass.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/PlayerArea.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/slimeWalk1.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/slimeWalk2.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/slimeDead.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/flyFly1.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/flyFly2.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/flyDead.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/cloud1.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/cloud2.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/cloud3.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/bush.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/cactus.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/plant.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/coinGold.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/shadedDark06.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/shadedDark05.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/shadedDark45.png',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/shadedDark09.png',

  // Space shooter images (see space-shooter.json in fixtures)
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/playerShip2_blue.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/meteorBrown_med1.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserBlue03.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/enemyBlack1.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/enemyBlue2.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/purpleSpaceBackground.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserBlue09.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserBlue10.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserBlue11.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/enemyGreen3.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserRed16.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserRed09.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserRed10.png',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/laserRed11.png',
];

const publicAudioUrls = [
  // Platformer audio (see platformer.json in fixtures)
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/jump.wav',
  'https://df5lqcdudryde.cloudfront.net/examples/platformer/coin.wav',

  // Space shooter audio (see space-shooter.json in fixtures)
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/sfx_laser1.ogg',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/sfx_twoTone.ogg',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/sfx_shieldDown.ogg',
  'https://df5lqcdudryde.cloudfront.net/examples/space-shooter/sfx_lose.ogg',
];

const nameFromUrl = (url: string): string => {
  const urlParts = url.split('/');
  return urlParts[urlParts.length - 1]
    .replace('.png', '')
    .replace('.wav', '')
    .replace('.ogg', '');
};

class GenericResourcesChooser extends Component {
  state = {
    open: false,
    resolveWithResources: null,
    chosenResourceUrl: null,
  };

  constructor(props) {
    super(props);

    // Cache rendered public images list to avoid doing this each time
    // a rendering is done.
    this.listItems = props.urls.map((url: string) => {
      return (
        <ListItem
          value={url}
          key={url}
          primaryText={nameFromUrl(url)}
          leftAvatar={props.urlsAreImages && <ListIcon src={url} />}
        />
      );
    });
  }

  chooseResources = (project, multiSelections = true): Promise<Array<any>> => {
    return new Promise(resolve => {
      this.setState({
        open: true,
        resolveWithResources: resolve,
      });
    });
  };

  _onChoose = () => {
    const { resolveWithResources, chosenResourceUrl } = this.state;
    if (!resolveWithResources) return;

    const newResource = this.props.createNewResource();
    newResource.setFile(chosenResourceUrl);
    newResource.setName(chosenResourceUrl);

    resolveWithResources([newResource]);
    this.setState({
      open: false,
      resolveWithResources: null,
    });
  };

  _onClose = () => {
    const { resolveWithResources } = this.state;
    if (!resolveWithResources) return;

    resolveWithResources([]);
    this.setState({
      open: false,
      resolveWithResources: null,
    });
  };

  _handleChangeResource = (e, chosenResourceUrl) => {
    this.setState({
      chosenResourceUrl,
    });
  };

  render() {
    // Avoid rendering the dialog if it's not opened.
    if (!this.state.open) return null;

    const actions = [
      <FlatButton label="Close" primary={false} onClick={this._onClose} />,
      <FlatButton
        label="Choose"
        primary={false}
        disabled={!this.state.chosenResourceUrl}
        onClick={this._onChoose}
      />,
    ];

    return (
      <Dialog
        title={this.props.title}
        actions={actions}
        open={this.state.open}
        noMargin
        autoScrollBodyContent
      >
        <div style={styles.explanations}>
          <p>
            Adding resources from Dropbox, Google Drive... is coming soon!
            Download GDevelop desktop version to use your own assets.
          </p>
        </div>
        <SelectableList
          value={this.state.chosenResourceUrl}
          onChange={this._handleChangeResource}
        >
          {this.listItems}
        </SelectableList>
      </Dialog>
    );
  }
}

export default [
  {
    name: 'publicAudioUrlChooser',
    displayName: 'Choose an audio file from library',
    kind: 'audio',
    component: class AudioResourceChooser extends React.Component {
      chooseResources = () => {
        if (this._chooser) return this._chooser.chooseResources();
      };
      render() {
        return (
          <GenericResourcesChooser
            {...this.props}
            urls={publicAudioUrls}
            urlsAreImages={false}
            createNewResource={() => new gd.AudioResource()}
            title="Choose an audio file from the library"
            ref={chooser => (this._chooser = chooser)}
          />
        );
      }
    },
  },
  {
    name: 'publicImageUrlChooser',
    displayName: 'Choose an image from library',
    kind: 'image',
    component: class AudioResourceChooser extends React.Component {
      chooseResources = () => {
        if (this._chooser) return this._chooser.chooseResources();
      };
      render() {
        return (
          <GenericResourcesChooser
            {...this.props}
            urls={publicImageUrls}
            urlsAreImages
            createNewResource={() => new gd.ImageResource()}
            title="Choose an image from the library"
            ref={chooser => (this._chooser = chooser)}
          />
        );
      }
    },
  },
];
