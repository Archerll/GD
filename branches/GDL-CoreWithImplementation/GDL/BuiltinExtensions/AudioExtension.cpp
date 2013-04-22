/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */

#include <iostream>
#include "GDL/BuiltinExtensions/AudioExtension.h"
#include "GDL/SoundManager.h"
#include "GDL/CommonTools.h"
#if defined(GD_IDE_ONLY)
#include "GDCore/IDE/ArbitraryResourceWorker.h"
#include "GDCore/Events/Instruction.h"
#endif

AudioExtension::AudioExtension()
{
    DECLARE_THE_EXTENSION("BuiltinAudio",
                          _("Audio"),
                          _("Builtin audio extension"),
                          "Compil Games",
                          "Freeware")

    #if defined(GD_IDE_ONLY)
    DECLARE_ACTION("PlaySoundCanal",
                   _("Play a sound on a channel"),
                   _("Play a sound ( small audio file ) on a specific canal,\nso as to be able to manipulate it."),
                   _("Play the sound _PARAM1_ on the channel _PARAM2_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("soundfile", _("Audio file"), "",false);
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("yesorno", _("Repeat the sound \?"), "",true).SetDefaultValue("no");
        instrInfo.AddParameter("expression", _("Volume ( From 0 to 100, 100 by default )"), "",true).SetDefaultValue("100");
        instrInfo.AddParameter("expression", _("Pitch ( speed ) ( 1 by default )"), "",true).SetDefaultValue("1");

        instrInfo.cppCallingInformation.SetFunctionName("PlaySoundOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("StopSoundCanal",
                   _("Stop the sound of a channel"),
                   _("Stop the sound on the specified channel."),
                   _("Stop the sound of channel _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("StopSoundOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("PauseSoundCanal",
                   _("Pause the sound of a channel"),
                   _("Pause the sound played on the specified channel."),
                   _("Pause the sound of channel _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("PauseSoundOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("RePlaySoundCanal",
                   _("Play the sound of a channel"),
                   _("Play the sound of the channel."),
                   _("Play the sound of channel _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("RePlaySoundOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlayMusicCanal",
                   _("Play a music on a channel"),
                   _("Play a music an on specific channel,\nso as to be able to interact with later."),
                   _("Play the music _PARAM1_ on channel _PARAM2_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("musicfile", _("Audio file"), "",false);
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("yesorno", _("Repeat the sound \?"), "",true).SetDefaultValue("no");
        instrInfo.AddParameter("expression", _("Volume ( From 0 to 100, 100 by default )"), "",true).SetDefaultValue("100");
        instrInfo.AddParameter("expression", _("Pitch ( speed ) ( 1 by default )"), "",true).SetDefaultValue("1");

        instrInfo.cppCallingInformation.SetFunctionName("PlayMusicOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("StopMusicCanal",
                   _("Stop the music on a channel"),
                   _("Stop the music on the specified channel"),
                   _("Stop the music of channel _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("StopMusicOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("PauseMusicCanal",
                   _("Pause the music of a channel"),
                   _("Pause the music on the specified channel."),
                   _("Pause the music of channel _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("PauseMusicOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("RePlayMusicCanal",
                   _("Play the music of a channel"),
                   _("Play the music of the channel."),
                   _("Play the music of channel _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("RePlayMusicOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModVolumeSoundCanal",
                   _("Volume of the sound on a channel"),
                   _("This action modify the volume of the sound on the specified channel. The volume is between 0 and 100."),
                   _("Do _PARAM3__PARAM2_ to the volume of the sound on channel _PARAM1_"),
                   _("Sound level"),
                   "res/actions/sonVolume24.png",
                   "res/actions/sonVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetSoundVolumeOnChannel").SetManipulatedType("number").SetAssociatedGetter("GetSoundVolumeOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModVolumeMusicCanal",
                   _("Volume of the music on a channel"),
                   _("This action modify the volume of the music on the specified channel. The volume is between 0 and 100."),
                   _("Do _PARAM3__PARAM2_ to the volume of the music on channel _PARAM1_"),
                   _("Sound level"),
                   "res/actions/sonVolume24.png",
                   "res/actions/sonVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetMusicVolumeOnChannel").SetManipulatedType("number").SetAssociatedGetter("GetMusicVolumeOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModGlobalVolume",
                   _("Game global volume"),
                   _("This action modify the global volumeof the game. The volume is between 0 and 100."),
                   _("Do _PARAM2__PARAM1_ to global sound level"),
                   _("Sound level"),
                   "res/actions/volume24.png",
                   "res/actions/volume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetGlobalVolume").SetAssociatedGetter("GetGlobalVolume").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPitchSoundChannel",
                   _("Pitch of the sound of a channel"),
                   _("This action modify pitch ( speed ) of the sound on a channel.\n1 is the default pitch."),
                   _("Do _PARAM3__PARAM2_ to the pitch of the sound on channel _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetSoundPitchOnChannel").SetAssociatedGetter("GetSoundPitchOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");


    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPitchMusicChannel",
                   _("Pitch of the music on a channel"),
                   _("This action modify the pitch of the music on the specified channel. 1 is the default pitch"),
                   _("Do _PARAM3__PARAM2_ to the pitch of the music on channel _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetMusicPitchOnChannel").SetAssociatedGetter("GetMusicPitchOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");


    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPlayingOffsetSoundChannel",
                   _("Playing offset of the sound on a channel"),
                   _("This action modify the playing offset of the sound on a channel"),
                   _("Do _PARAM3__PARAM2_ to the playing offset of the sound on channel _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetSoundPlayingOffsetOnChannel").SetAssociatedGetter("GetSoundPlayingOffsetOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("ModPlayingOffsetMusicChannel",
                   _("Playing offset of the music on a channel"),
                   _("This action modify the playing offset of the music on the specified channel"),
                   _("Do _PARAM3__PARAM2_ to the playing offset of the music on channel _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Value"), "",false);
        instrInfo.AddParameter("operator", _("Modification's sign"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SetMusicPlayingOffsetOnChannel").SetAssociatedGetter("GetMusicPlayingOffsetOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlaySound",
                   _("Play a sound"),
                   _("Play a sound."),
                   _("Play the sound _PARAM1_"),
                   _("Sounds"),
                   "res/actions/son24.png",
                   "res/actions/son.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("soundfile", _("Audio file"), "",false);
        instrInfo.AddParameter("yesorno", _("Repeat the sound \?"), "",true).SetDefaultValue("no");
        instrInfo.AddParameter("expression", _("Volume ( From 0 to 100, 100 by default )"), "",true).SetDefaultValue("100");
        instrInfo.AddParameter("expression", _("Pitch ( speed ) ( 1 by default )"), "",true).SetDefaultValue("1");

        instrInfo.cppCallingInformation.SetFunctionName("PlaySound").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_ACTION("PlayMusic",
                   _("Play a music"),
                   _("Play a music."),
                   _("Play the music _PARAM1_"),
                   _("Musics"),
                   "res/actions/music24.png",
                   "res/actions/music.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("musicfile", _("Audio file"), "",false);
        instrInfo.AddParameter("yesorno", _("Repeat the sound \?"), "",true).SetDefaultValue("no");
        instrInfo.AddParameter("expression", _("Volume ( From 0 to 100, 100 by default )"), "",true).SetDefaultValue("100");
        instrInfo.AddParameter("expression", _("Pitch ( speed ) ( 1 by default )"), "",true).SetDefaultValue("1");

        instrInfo.cppCallingInformation.SetFunctionName("PlayMusic").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_ACTION()

    DECLARE_CONDITION("MusicPlaying",
                   _("A music is being played"),
                   _("Test if the music on a channel is being played"),
                   _("The music on channel _PARAM1_ is being played"),
                   _("Musics"),
                   "res/conditions/musicplaying24.png",
                   "res/conditions/musicplaying.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("MusicPlaying").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicPaused",
                   _("A music is paused"),
                   _("Test if the music on the specified canal is paused."),
                   _("The music on channel _PARAM1_ is paused"),
                   _("Musics"),
                   "res/conditions/musicpaused24.png",
                   "res/conditions/musicpaused.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("MusicPaused").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicStopped",
                   _("A music is stopped"),
                   _("Test if the music on the specified canal is stopped."),
                   _("The music on channel _PARAM1_ is stopped"),
                   _("Musics"),
                   "res/conditions/musicstopped24.png",
                   "res/conditions/musicstopped.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("MusicStopped").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()
    DECLARE_CONDITION("SoundPlaying",
                   _("A sound is being played"),
                   _("Test if the sound on a channel is being played."),
                   _("Thee sound on channel _PARAM1_ is being played"),
                   _("Sounds"),
                   "res/conditions/sonplaying24.png",
                   "res/conditions/sonplaying.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SoundPlaying").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundPaused",
                   _("A sound is paused"),
                   _("Test if the sound on the specified canal is paused."),
                   _("The sound on channel _PARAM1_ is paused"),
                   _("Sounds"),
                   "res/conditions/sonpaused24.png",
                   "res/conditions/sonpaused.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SoundPaused").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundStopped",
                   _("A sound is stopped"),
                   _("Test if the sound on the specified canal is stopped."),
                   _("The sound on channel _PARAM1_ is stopped"),
                   _("Sounds"),
                   "res/conditions/sonstopped24.png",
                   "res/conditions/sonstopped.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("SoundStopped").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundCanalVolume",
                   _("Volume of the sound on a channel"),
                   _("Test the volume of the sound on the specified channel. The volume is between 0 and 100."),
                   _("The volume of the sound on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Sound level"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Volume to test"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundVolumeOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicCanalVolume",
                   _("Volume of the music on a channel"),
                   _("Test the volume of the music on specified channel. The volume is between 0 and 100."),
                   _("The volume of the music on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Sound level"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Volume to test"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicVolumeOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("GlobalVolume",
                   _("global"),
                   _("Test the global sound level. The volume is between 0 and 100."),
                   _("The global game volume is _PARAM2_ to _PARAM1_"),
                   _("Sound level"),
                   "res/conditions/volume24.png",
                   "res/conditions/volume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Volume to test"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetGlobalVolume").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundChannelPitch",
                   _("Pitch of the sound of a channel"),
                   _("Test the pitch of the sound on the specified channel. 1 is the default pitch."),
                   _("The pitch of the sound on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Sounds"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Pitch to test"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundPitchOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicChannelPitch",
                   _("Pitch of the music on a channel"),
                   _("Test the pitch ( speed ) of the music on specified channel. 1 is the default pitch."),
                   _("The volume of the music on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Musics"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Pitch to test"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicPitchOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("SoundChannelPlayingOffset",
                   _("Playing offset of the sound on a channel"),
                   _("Test the playing offset of the sound on the specified channel."),
                   _("The playing offset of the sound on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Sounds"),
                   "res/conditions/sonVolume24.png",
                   "res/conditions/sonVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Position ( in seconds )"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundPlayingOffsetOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_CONDITION("MusicChannelPlayingOffset",
                   _("Playing offset of the music on a channel"),
                   _("Test the playing offset of the music on the specified channel."),
                   _("The playing offset of the music on channel _PARAM1_ is _PARAM3__PARAM2_"),
                   _("Musics"),
                   "res/conditions/musicVolume24.png",
                   "res/conditions/musicVolume.png");

        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Canal ( 0 - 15 )"), "",false);
        instrInfo.AddParameter("expression", _("Position ( in seconds )"), "",false);
        instrInfo.AddParameter("relationalOperator", _("Sign of the test"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicPlayingOffsetOnChannel").SetManipulatedType("number").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");

    DECLARE_END_CONDITION()

    DECLARE_EXPRESSION("SoundChannelPlayingOffset", _("Sound playing offset"), _("Sound playing offset"), _("Sounds"), "res/actions/son.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundPlayingOffsetOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelPlayingOffset", _("Music playing offset"), _("Music playing offset"), _("Musics"), "res/actions/music.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicPlayingOffsetOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("SoundChannelVolume", _("Sound volume"), _("Sound volume"), _("Sounds"), "res/actions/son.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundVolumeOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelVolume", _("Music volume"), _("Music volume"), _("Musics"), "res/actions/music.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicVolumeOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("SoundChannelPitch", _("Sound's pitch"), _("Sound's pitch"), _("Sounds"), "res/actions/son.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetSoundPitchOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("MusicChannelPitch", _("Music's pitch"), _("Music's pitch"), _("Musics"), "res/actions/music.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");
        instrInfo.AddParameter("expression", _("Channel"), "",false);

        instrInfo.cppCallingInformation.SetFunctionName("GetMusicPitchOnChannel").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    DECLARE_EXPRESSION("GlobalVolume", _("Global volume"), _("Global volume value"), _("Sound level"), "res/conditions/volume.png")
        instrInfo.AddCodeOnlyParameter("currentScene", "");

        instrInfo.cppCallingInformation.SetFunctionName("GetGlobalVolume").SetIncludeFile("GDL/BuiltinExtensions/AudioTools.h");
    DECLARE_END_EXPRESSION()
    #endif
}

#if defined(GD_IDE_ONLY)
void AudioExtension::ExposeActionsResources(gd::Instruction & action, gd::ArbitraryResourceWorker & worker)
{
    if ( action.GetType() == "PlaySound" || action.GetType() == "PlaySoundCanal" || action.GetType() == "PlayMusic" || action.GetType() == "PlayMusicCanal" )
    {
        std::string parameter = action.GetParameter(1).GetPlainString();
        worker.ExposeResource(parameter);
        action.SetParameter(1, parameter);
    }
}

void AudioExtension::GetPropertyForDebugger(RuntimeScene & scene, unsigned int propertyNb, std::string & name, std::string & value) const
{
    if ( propertyNb == 0 )
    {
        name = _("Global volume:");
        value = ToString(SoundManager::GetInstance()->GetGlobalVolume());
    }
    else if ( propertyNb < 1+SoundManager::GetInstance()->sounds.size()*3 )
    {
        unsigned int soundNb = ((propertyNb-1)-(propertyNb-1)%3)/3;
        if (soundNb >= SoundManager::GetInstance()->sounds.size()) return;

        if ( propertyNb % 3 == 1)
        {
            sf::Sound::Status soundStatus = SoundManager::GetInstance()->sounds[soundNb]->GetStatus();

            if ( soundStatus == sf::Sound::Playing)
                name = _("Sound played:");
            else if ( soundStatus == sf::Sound::Stopped)
                name = _("Sound stopped:");
            else if ( soundStatus == sf::Sound::Paused)
                name = _("Paused sound:");

            value = SoundManager::GetInstance()->sounds[soundNb]->file;
        }
        else if ( propertyNb % 3 == 2)
        {
            name = _(" -Volume/Pitch:");
            value = ToString(SoundManager::GetInstance()->sounds[soundNb]->GetVolume())
                    +"/"+ToString(SoundManager::GetInstance()->sounds[soundNb]->GetPitch());
        }
        else
        {
            name = _(" -Progress (seconds) :");
            value = ToString(SoundManager::GetInstance()->sounds[soundNb]->GetPlayingOffset());
        }

    }
    else if ( propertyNb < 1+SoundManager::GetInstance()->sounds.size()*3+SoundManager::GetInstance()->musics.size()*3 )
    {
        unsigned int musicNb = ((propertyNb-1-SoundManager::GetInstance()->sounds.size()*3)-(propertyNb-1-SoundManager::GetInstance()->sounds.size()*3)%3)/3;
        if (musicNb >= SoundManager::GetInstance()->musics.size()) return;

        if ( propertyNb % 3 == 1)
        {
            sf::Sound::Status soundStatus = SoundManager::GetInstance()->musics[musicNb]->GetStatus();

            if ( soundStatus == sf::Sound::Playing)
                name = _("Played music:");
            else if ( soundStatus == sf::Sound::Stopped)
                name = _("Stopped music:");
            else if ( soundStatus == sf::Sound::Paused)
                name = _("Paused music:");

            value = SoundManager::GetInstance()->musics[musicNb]->file;
        }
        else if ( propertyNb % 3 == 2)
        {
            name = _(" -Volume/Pitch:");
            value = ToString(SoundManager::GetInstance()->musics[musicNb]->GetVolume())
                    +"/"+ToString(SoundManager::GetInstance()->musics[musicNb]->GetPitch());
        }
        else
        {
            name = _(" -Progress (seconds) :");
            value = ToString(SoundManager::GetInstance()->musics[musicNb]->GetPlayingOffset());
        }
    }
}

bool AudioExtension::ChangeProperty(RuntimeScene & scene, unsigned int propertyNb, std::string newValue)
{
    if ( propertyNb == 0 )
    {
        SoundManager::GetInstance()->SetGlobalVolume(ToFloat(newValue));
        return true;
    }
    else if ( propertyNb < 1+SoundManager::GetInstance()->sounds.size()*3 )
    {
        unsigned int soundNb = ((propertyNb-1)-(propertyNb-1)%3)/3;
        if (soundNb >= SoundManager::GetInstance()->sounds.size()) return false;

        if ( propertyNb % 3 == 1)
        {
            return false;
        }
        else if ( propertyNb % 3 == 2)
        {
            std::vector<string> values = SplitString<string>(newValue, '/');
            if ( values.size() < 2 ) return false;

            SoundManager::GetInstance()->sounds[soundNb]->SetVolume(ToFloat(values[0]));
            SoundManager::GetInstance()->sounds[soundNb]->SetPitch(ToFloat(values[1]));
            return true;
        }
        else
        {
            SoundManager::GetInstance()->sounds[soundNb]->SetPlayingOffset(ToFloat(newValue));
            return true;
        }

    }
    else if ( propertyNb < 1+SoundManager::GetInstance()->sounds.size()*3+SoundManager::GetInstance()->musics.size()*3 )
    {
        unsigned int musicNb = ((propertyNb-1-SoundManager::GetInstance()->sounds.size()*3)-(propertyNb-1-SoundManager::GetInstance()->sounds.size()*3)%3)/3;
        if (musicNb >= SoundManager::GetInstance()->musics.size()) return false;

        if ( propertyNb % 3 == 1)
        {
            return false;
        }
        else if ( propertyNb % 3 == 2)
        {
            std::vector<string> values = SplitString<string>(newValue, '/');
            if ( values.size() < 2 ) return false;

            SoundManager::GetInstance()->musics[musicNb]->SetVolume(ToFloat(values[0]));
            SoundManager::GetInstance()->musics[musicNb]->SetPitch(ToFloat(values[1]));
            return true;
        }
        else
        {
            SoundManager::GetInstance()->musics[musicNb]->SetPlayingOffset(ToFloat(newValue));
            return true;
        }
    }


    return false;
}

unsigned int AudioExtension::GetNumberOfProperties(RuntimeScene & scene) const
{
    return 1+SoundManager::GetInstance()->musics.size()*3+SoundManager::GetInstance()->sounds.size()*3;
}

#endif
