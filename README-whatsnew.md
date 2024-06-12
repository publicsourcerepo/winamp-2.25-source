Winamp 5.24
* Fixed: [in_midi] crash bug & potential security vulnerability

Winamp 5.23
* Improved: [gen_jumpex] jump-to-file speed improvements
* Fixed: playlist saving with network share files
* Fixed: Media Library preferences not loading in correct order
* Fixed: main window not hilited when restoring from minimized state in classic skin.
* Fixed: slow loading of playlists with URLs
* Fixed: CD burning using third party input plugins
* Fixed: classic skin winshade playlist time display
* Fixed: [gen_ff] Wasabi XML font-related fixes from Martin Poehlmann
* Fixed: [gen_ff] Map.getHeight() maki script function returning width instead
* Fixed: [gen_ff] winshade global hotkeys broken w/ modern skins
* Fixed: [gen_jumpex] 'Add to Queue' issues
* Fixed: [gen_jumpex] NT4 incompatability
* Fixed: [gen_jumpex] misc bug fixes
* Fixed: [gen_ml] icon changes on drag+drop items
* Fixed: [in_mp3] playback of AAC streams
* Fixed: [in_mp4] seek bug when using right arrow key
* Fixed: [in_wm] Playback restarts from beginning when editing tags of a currently playing .wma file
* Fixed: [in_wm] protocol/extension reversed in config > filetype > edit
* Fixed: [in_wm] 'Audio only' always checked for ASF/WMV in config
* Fixed: [in_wm] seek bug when using right arrow key
* Fixed: [ml_bookmarks] 'Edit Bookmarks' menu item not working when Media Library is hidden
* Fixed: [ml_local] crash while rearranging media library views
* Fixed: [ml_local] crash on close
* Fixed: [ml_local] sort arrow reversed in some columns
* Fixed: [ml_playlists] Import Playlists uses containing dir for title instead of filename
* Fixed: [ml_playlists] No "Recurse" checkbox in Import Playlists From Folder
* Fixed: [ml_playlists] Add Dir adds all filetypes (not just all-supported)
* Fixed: [ml_playlists] rt-click enqueue not working & other issues
* Fixed: [ml_playlists] Not saving playlists in some situations
* Fixed: [ml_playlists] crash when loading badly formed WPL playlists
* Fixed: [ml_playlists] drag&drop into playlist not adding to correct position
* Fixed: [ml_playlists] root playlist screen not updating when adding new playlist
* Fixed: [ml_playlists] reverting changes on send-to: playlist
* Fixed: [ml_playlists] drag+drop m3u files broken
* Fixed: [ml_pmp] Syncing duplicates finally fixed (thanks gordol)
* Fixed: [ml_pmp] Removing items from a playlist not saving issue (thanks Nick)
* Fixed: [ml_wire] some podcasts only display one item
* Fixed: [pmp_ipod] Playlist sort now works again
* Fixed: [out_ds] stop with fade (shift+v) issue
* Updated: [in_cdda] CDDB 2.0.1.25

Winamp 5.22
* New: loading of additional playlist formats: ASX/WAX/WMX/WVX, WPL, B4S
* New: [gen_ff] modern skin unicode support
* New: [in_wm] burning of DRM protected files (if allowed by content provider)
* New: [ml_pmp] transfer of playlists to portable devices
* Improved: More informative CD burning status window
* Improved: [gen_ff] modern skinning engine speed optimizations
* Improved: [gen_jumpex] jump-to-file search response
* Improved: [gen_tray] enhanced icon pack support plus more... (thanks DrO)
* Improved: [in_wm] seeking improvements
* Improved: [in_wm] gapless WMA support
* Improved: [ml_nowplaying] Redesigned 'Now Playing' media library view
                            (it actually works now)
* Improved: [pmp_ipod] Loading times for iPods reduced
* Fixed: Winamp won't restore after being minimized with a dialog box open
* Fixed: $abbr() title formatting lockup
* Fixed: Add Folder adds tracks BEFORE the last track
* Fixed: Clicking 'Next' in Fullscreen video OSD acts like clicking it twice
* Fixed: Rating in pledit right-click context menu always shows "No Rating"
* Fixed: Stop with fadeout (Shift+V) just stops playback, no fadeout
* Fixed: CD burning bugs and crashes
* Fixed: Delete key not working in Online Services or SC Wire search
* Fixed: [gen_jumpex] handling of playlist with more than 65,536 files
* Fixed: [gen_jumpex] 'on end of queue' fixed
* Fixed: [gen_jumpex] modern skin pledit docked toolbar mode not remembered
* Fixed: [gen_jumpex] ML size/position not remembered when switching from Classic to Modern and back to Classic skin
* Fixed: [gen_jumpex] misc bug fixes
* Fixed: [gen_ml] playlists root view slowness bug
* Fixed: [gen_ml] Modern skin: Media Library > View (menu) > Devices 
* Fixed: [in_midi] corrupt header crash
* Fixed: [in_mp4] metadata writing crash
* Fixed: [in_mp4] seek bug when using right arrow key
* Fixed: [in_mp3] MPEG-2 and MPEG-2.5 Layer 3 playback crash
* Fixed: [in_mp3] Winamp crashes when trying to play any wrongly named .aac file
* Fixed: [in_wave] WAV burning fix
* Fixed: [in_wave] Locking files (wav's can't be renamed/deleted)
* Fixed: [in_wm] lockup on wma with expired/unrenewable drm license
* Fixed: [in_wm] out of sync audio/video on some WMV streams
* Fixed: [in_vorbis] fullpath shown in playlist for tagless files with atf disabled
* Fixed: [ml_pmp] Duplicates being synchronized
* Fixed: [ml_pmp] Several crashes during transfers 
* Fixed: [out_ds] Can't select different Output Device with two active instances of out_ds
* Fixed: [out_ds] incorrect enumeration of stereo outputs for two of same pro soundcard

Winamp 5.21
* New: [jnetlib] HTTP compression support
* Improved: [installer] multi-user profile migration
* Fixed: [ml_wire] memory leak
* Fixed: [pmp_p4s] DRMclien.dll error
* Fixed: [gen_ff] skin info display in preferences
* Fixed: [in_mp3] Wordwrap disabled in Info Editor Comments field
* Fixed: [in_wm] Minor bug fixes
* Fixed: Keyboard shortcuts don't work from video window
* Fixed: [in_vorbis] No Artist metadata in stream titles
* Fixed: [in_dshow] floating point audio 
* Updated: Coding Technology AAC+ Decoder 7.2.5

Winamp 5.2
* New: [ml_pmp] Synchronize your Media Library with your portable media player 
                Compatible with iPod, Creative, and Microsoft Plays For Sure devices
* New: [enc_aacplus] Coding Technologies aacPlus High Bitrate encoder available in Winamp Pro
* New: [enc_aacplus] Coding Technologies aacPlus (HE-AAC) in MP4 container
* New: [enc_aacplus] Coding Technologies LC-AAC encoder
* New: [gen_ml] icons in treeview
* New: [ml_online] Dynamic AJAX Internet Media Hub
* New: [in_nsv] Using Coding Technologies AAC playback within NSV container
* New: [in_mp3] gapless MP3 playback
* New: [installer] multi-user profile options
* New: [installer] remembers your previous installer settings
* New: [in_wave] in_wave 3.0
* New: right-to-left playlist display
* Improved: new ATF functions and tags, including:
            $repeat(x, count) - creates a string with x repeated count times
            $lpad() - same as $pad, but adds padding to the left
            $decode(...) - switch/case function.  example: $decode($fileext(%filename%),MP3,MPEG-1 Layer 3,MP4,MPEG-4 Container,Other)
            $IfStrEqual(string1,string2,result) - if string1 and string2 are equal, displays result.  case insensitive
            $IfStrEqual2(string1,string2,result,else) - if string1 and string2 are equal, displays result, otherwise displays else.  case insensitive
            %folder% - top level folder name of the file
* Improved: Stereo beat visualization for modern skins
* Improved: [gen_ff] new vis modes available to skinners
* Improved: [gen_ml] CD drive info view (Rip & Burn)
* Improved: [gen_tray] gen_tray v1.0 (thanks DrO)
* Improved: [in_midi] provides metadata to media library
* Improved: [in_mod] provides metadata to media library
* Improved: [in_mp3] unicode id3 tags
* Improved: [in_mp3] preliminary id3v2.4 support
* Fixed: broken playlist sorting
* Fixed: playlist problems with multi-line tags (e.g. %comment%)
* Fixed: shuffle with only one song in playlist
* Fixed: ghost seek slider appears if Winamp loses focus during seeking
* Fixed: video options from video window right-click context menu
* Fixed: playlist winshade international character support
* Fixed: fullscreen video display international character support
* Fixed: m3u playlist handling security vulnerability (thanks to NSFOCUS and Information Risk Management Plc)
* Fixed: [enc_lame] bit reservoir
* Fixed: [enc_lame] cutoff of last frame
* Fixed: [gen_ff] regions on components don't work
* Fixed: [gen_ff] playlist & video focus bug
* Fixed: [gen_ff] playlist winshade memory leak 
* Fixed: [gen_ff] GDI Object leak with Current Skin prefs page
* Fixed: [in_midi] not following winamp's title formatting options
* Fixed: [in_midi] reset button blocks further access to config
* Fixed: [in_mod] not following winamp's title formatting options
* Fixed: [in_mp3] incorrect version identification (showed 5.18 in 5.12)
* Fixed: [in_mp3] incorrect information shown for AAC+ files
* Fixed: [in_mp3] reading incorrect id3 comment tag
* Fixed: [in_mp3] sometimes failing to read last id3 frame
* Fixed: [in_mp3] id3v2 album art loss when editing tags
* Fixed: [in_mp4] loss of album art when modifying metadata
* Fixed: [in_vorbis] not following winamp's title formatting options
* Fixed: [in_vorbis] registry usage (now multi-user profile safe)
* Fixed: [in_wave] 32bit floating point WAV playback distortion
* Fixed: [in_wm] changes made with Attribute Editor not updating in ML/Playlist
* Fixed: [vis_milk] missing files from distro (you can stop bugging us now, Rovastar :)
* Fixed: [vis_milk] 100% cpu usage when paused
* Updated: [gen_jumpex] DrO's Jump To File Extension 0.97 
* Updated: [enc_lame] LAME 3.97b2
* Updated: [gen_ff] libpng 1.2.8
* Updated: [gen_ff] FreeType 2.1.10
* Updated: [enc_aacplus] Coding Technologies aacPlus encoder v7.2.0a

Winamp 5.13
* Fixed: [in_mp3] extremely critical security vulnerability

Winamp 5.12
* New: [in_wm] Windows Media Video support (with DRM)
* New: [in_mp4] Support for HE-AAC MP4/M4A files
* Improved: lots of minor plugin improvements
* Improved: Visualization data calculations
* Improved: Significantly less playlist memory usage
* Improved: more multi-user improvements (almost there!)
* Improved: [installer] setup options, saved settings, codec downloading
* Improved: [gen_ff] optimized skinning engine
* Improved: [out_disk] new features
* Improved: [in_cdda] playback/ripping with sonic engine
* Fixed: freezing when cancelling cd burn
* Fixed: video scaling bug (with modern skin scaling < 100%)
* Fixed: minor installer bugs
* Fixed: freeze when loading classic skin with main window hidden
* Fixed: Visualizations for 24bit and 32bit songs
* Fixed: Advanced Title Formatting with Japanese, Chinese and Korean metadata (thanks mrym)
* Fixed: [in_mp3] raw AAC VBR file seeking and bitrate reporting
* Fixed: [in_mp4] unicode metadata writing 
* Fixed: [in_wm/in_dshow] mms:// streaming video playback
* Fixed: [in_cdda] audio cd bitrate display
* Fixed: [in_cdda] Sonic engine on 64bit windows (thanks STanger)
* Fixed: lots of small bugs ...
* Updated: Sonic CD Engine 2.2.50
* Updated: libmp4v2 1.4.1
* Updated: Coding Technology AAC+ Decoder 7.2.0

Winamp 5.111
* Fixed: works with internet explorer 3.0 again (old win95/nt3.51)
* Fixed: Auto-Preset EQ crash (non-mp3 files)
* Fixed: $upper, $caps, $caps2 crash with foreign characters
* Fixed: Station Info crash (with http filtering program)
* Fixed: empty playlist bugs
* Fixed: [in_mp3] proxy ignored when �only port 80� was checked
* Fixed: [in_midi] lyrics not working

Winamp 5.11
* Updated: LAME 3.96.1
* Fixed: playlist focus issue after adding files to playlist
* Fixed: crash on multichannel songs with EQ enabled
* Fixed: internet connection detection not working when set to "dial-up"
* Fixed: manual playlist advance with winamp videos
* Fixed: EQ text display glitch
* Fixed: video not filling up video window
* Fixed: black bars in fullscreen video
* Fixed: [gen_ml] crash with no write access
* Fixed: [gen_ml] CDDB Dialog Media Library drawing glitch
* Fixed: [in_dshow] seeking on files with no video or no audio
* Fixed: [in_cdda] aspi ripping crash
* Fixed: [ml_wire] "my music" folder creation
* Fixed: [ml_wire] Podcasts with dates before 1970 handled properly
* Fixed: [ml_wire] Downloading of podcasts with parameters in URL
* Fixed: [out_ds] fade-on-seek settings
* Fixed: [in_wm] pause glitch
* Fixed: [in_mp4] view-file-info filename not scrolling
* Coming Soon: Multi-user profile support (preliminary support enabled)

Winamp 5.1 Surround Edition
* New: CodingTechnologies AACPlus encoder! 
	The MP3 Killer! 
	Awesome at low bitrates too!
* New: Grand Prize Winner of the Internet Surround Music Project!
	KAJE - Hey Buddy (featuring Afrika Bambaataa)
* New: SHOUTcast Wire - A Media RSS Browser and Subscription Service
* New: Predixis Smart Playlist Generator 
	(Mix your tracks based on what they sound like!)
* New: AOL Radio featuring (((XM))) Free Sampler!
* New: CD Ripping now available at 8x in free version!
* New: Microsoft WMA encoder
* New: Over 200 new Milkdrop presets!
* Update: in_vorbis now returns bitrate in getextendedfileinfo
* Fixed: WMA stuttery playback
* Fixed: out_ds copy button on status tab now works all the time
* Fixed: Much improved ripping and playback with Sonic engine
* Fixed: Video window now resizable regardless of Sidecar
* Fixed: Length of long mp3's now reported properly 
* Fixed: Silent install switch now works properly
* Fixed: Simultaneous CD Playback and Ripping 

Winamp 5.094
* New: in_wm now handles bitrate and length extended info
* New: New random number generation for playlist shuffle
* Fixed: Security vulnernability in id3v2 tags (thanks to LSS Security)
* Fixed: Winamp now shuffles playlists larger than 32,768 songs
* Fixed: Fade on start now behaves properly
* Fixed: separate directsound settings with multiple instances
* Fixed: Winamp now supports adding URLs longer than 260 characters.
* Fixed: Editing files created in iTunes no longer causes corruption.
* Fixed: Length of long mp3's now reported properly
* Fixed: gen_jumpex no longer crashes when DEP is enabled
* Fixed: Sort selections in media library are now remembered.
* Fixed: Album names with non-alphanumeric characters behave better
* Fixed: Fixed intermittent crash on seeking for some users
* Updated: libmp4v2.dll


Winamp 5.093
* Fixed: OSD stays onscreen in DirectDraw Mode
* Fixed: Fullscreen video OSD doesn't reappear after using Pause
* Fixed: ML Playlist > Select all (no delete key)
* Fixed: Vis data for in_mod (and possibly other input plugins)
* Fixed: msvcp60.dll now linked static
* Fixed: Small  intermittent bugs in gen_ml and gen_ff
* Fixed: Greater than 2 channel vis data now works
* Fixed: Media Library problems with parentheses/brackets in artist or album names
* Fixed: Ripping CDs with trailing ellipses (...) in artist or album name
* Fixed: Better video flipping for YUV colorspace videos
* Fixed: Saved mute settings with modern skin.
* Fixed: Drag and Drop from external applications
* Fixed: Open File Dialog always-on-top
* Fixed: Crossfade on start
* Fixed: Freeze when switching audio tracks in a multi-audio stream.
* Fixed: Fullscreen switching with scaled video window.
* Update: Dynamic Online Media can now alert users to live events(can disable).

Winamp 5.092
* New: DRM WMA Playback supports out_wave
* New: Non-DRM WMA Playback allows any output plugin
* New: Community Picks AVS Preset Pack
* New: Deletes in the Media Library now move files to the Recycle Bin
* New: NSV Subtitles can be disabled on the fly
* Fixed: Long delay and high cpu on exit with many items in playlist
* Fixed: gen_ml shutdown bug
* Fixed: Easy Move of video window back to normal
* Fixed: Pause in WMA playback memory leak
* Fixed: Multi-monitor full screen video
* Fixed: Drag and Drop in playlist editor
* Fixed: Drag and Drop on Winamp
* Fixed: Now Playing update on song change
* Fixed: Media Library/Windows Media scanning errors
* Fixed: Stay in fullscreen/Config mismatch
* Fixed: Ctrl-B Crash
* Fixed: Authentication for OGG/Vorbis streams
* Fixed: Drag and Drop strange behavior in open file dialogs
* Fixed: Stuttering WMA On Start and Seek
* Fixed: NSV Video stall during buffering
* Fixed: Autosize of video to be accurate to the Video size not snap size
* Fixed: Short NSV Clips audio cutout
* Update: Online Media tree is now dynamic (Checking can now be disabled)
* Update: Sonic Install/Config flag mismatch
* Update: CD Ripping/Burning Library (possible cause of msvcrt.dll errors)

Winamp 5.08:
* Updated Windows Media DRM License
* Fixed playFile function in gen_ff.dll (Allows Modern skins to launch playback)
* Created new eMusic bundles
* Critical Security bug fixed in in_mp4.dll and enc_mp4.dll and libmp4v2.dll
* HTTP Seeking corrected for webservers that refuse to return Accept-Range
* Critical Security buffer overflow fixed in in_cdda.dll

Winamp 5.07:
* Critical Security bug fixed in in_cdda.dll and .m3u handler
* in_mp3 & in_nsv should work on Win95 again
* Proxy settings work again
* Installer fixed so that read_file.dll is installed always with mod support
* Version number should be properly reported by IPC_GETVERSION for this build

Winamp 5.06:
* Fixed crashbug when clearing the playlist and then right clicking on the songticker
* Security bug fixes
* Lots of small bugfixes
* JTFE v0.96ff

Winamp 5.05:
* Security bug fix
* Fix for upside down videos through DirectShow
* JTFE v0.96c
* Added prompt when loading a skin for the first time

Winamp 5.04a:
* fixed drag & drop on docked toolbar at startup
* modern skin updates :
  fixed lockup when exiting while in runModal

Winamp 5.04:
* update JTFE
* Added Coding Technologies' AACPlus decoder
* fixed deletion of temporary generated WAV files after a burning process on some 
  computers
* fixed typo in some context menu shortcuts
* fixed slowness IPC bug caused by gen_hotkeys
* added "clear" button in internet radio/tv views
* added screenshots of classic/modern mode in installer
* fixed MP3 bitrate calculation (in_mp3 was reporting incorrect lengths on some MP3s)
* fixed incorrect length reporting on long WMA files
* better fix for pledit/video windows showing up at startup when minimized
* fixed db text bug when moving EQ sliders
* upgraded MP3 encoding to LAME v3.96
* fixed crash in WMA playback when using WMA v8 codecs
* updated default streaming values in in_nsv
* added Winamp.com Audio&Video views in the Media Library
* fixed tiny memory leak in in_cdda
* added right click context menu on "Now Playing" item in Media Library
* added script/ActiveX disabling for Media Library's minibrowser (on by default)
* fixed memory leak on MP3 files with messed up ID3v2 tags
* fixed visualization when playing CD tracks
* fixed proxy user:pass@server:port string getting cut when playing Shoutcast streams
* made in_dshow not to handle mms:// streams ending with .wma
* fixed %tracknumber% tag for CD tracks
* fixed some crash bugs in in_mp4
* fixed playlist generation when ripping full CDs
* added "import playlist from folder" in Media Library
* updated Media Library preferences screens
* added new SPS presets from Cockos, Inc. (pitch shifters, etc...)
* added basic streaming (download) support for M4A/MP4 HTTP streams
* added monitoring of fullscreen apps, disables always on top temporarilly
* added IPC_IS_WNDSHADE
* added gen_ml rating ipcs
* added ratings from playlist context menu (acts on selected entries)
* added ratings from song ticker context menu (acts on current track)
* added rating hotkeys in gen_hotkey
* fixed saving read-only playlists
* fixed double separator lines in gen_ml id3less item context menu
* fixed refresh of view losing query after removing dead files & background scan
* added escaping of ", ', [ and ] in ml queries : uses %HH where HH is the hex char code (uses %% for '%')
* added sdk support for multiple audio/video tracks in video input plugins (see wa_ipc.h for ITrackSelector class)
* added multiple audio avi support (right click video window, select "Audio Tracks")
* fixed multimonitor problem when toggling a windowshade on one monitor while playing a fullscreen video on the other
* added ML_IPC_EDITQUERY and ML_IPC_EDITVIEW
* fixed pledit drawing bug under winxp/cleartype
* fixed crash in id3 reading of zero byte files
* fixed crash in sps when exiting winamp before closing the open/save dialog
* added IPC_PUSH_DISABLE_EXIT, IPC_POP_DISABLE_EXIT and IPC_IS_EXIT_ENABLED
* fixed gen_ml crash when inserting item with length -1
* made gen_ml much more resistant to databases that have been corrupted
* fixed ml nuke
* added disabling of "keep on screen" option when going into a different resolution because of a 
  fullscreen application (ie: a game)
* made ui:preferences global hotkey open the prefs to the previously opened page
* fixed a few preferences cosmetic 'bugs'
* modern skin updates :
  - fixed windowshade repeat-track button state
  - fixed scaling docked toolbars
  - fixed 5.03 assert on deletion of newGroupAsLayout()
  - fixed floating video windows coordinates dropping to 0,0
  - fixed auto opaque when layouts are loaded already docked as toolbars
  - fixed fadein/fadeout not used on notification window when linking all normal windows' 
    alpha
  - fixed docked toolbars moving when some other window docked to them switches to an 
    alternative layout
  - fixed silent crash on shutdown when pledit is docked as toolbar and gen_ml unloads 
    before gen_ff (would not remember settings from session to session)
  - fixed snap points
  - fixed click on +12db / 0db / -12db
  - optimized text scrolling (a lot)
  - fixed content of pledit not painting in some instances
  - gen_hotkeys are now routed thru System.onKeyDown(name), where name is the name of 
    the hotkey prefixed by "HOTKEY: " (ie: "HOTKEY: Playback: Play"). You may issue a
    complete; statement to prevent gen_hotkey from handling the hotkey
  - fixed horizontal resize of main window with video/vis drawer closed and config drawer open
  - added auto-height for next drawer opening when resizing main window with video/vis drawer closed,
    this avoids having an unreasonably tall drawer open if you just watched a video in a big window and
    then only resized the player back to its horizontal minimum after the video had closed. auto-height
    resets to 4:3 proportions
  - fixed docking bug when using snapadjustleft
  - fixed buggy calculation of time display default width conflicting with right text alignment
  - fixed windows moving after changing screen resolution
  - fixed rare always on top desync with classic skins

Winamp 5.03:
* made MP4 AAC the new default ripping encoder
* fixed a crash bug when playing some AVI files in in_dshow
* added multimedia keyboard keys in global hotkeys default configuration
* added "Manual playlist advance" in Repeat button popup menu in Classic mode
* improvements in MP3 encoder configuration (added --alt-preset standard, etc...)
* made the tabs in the preferences XP correctly themed under Windows XP
* revamped the Media Library preferences a bit
* new experimental WMA9 input plugin
* gen_jumpex updates from DrO
* added "Nuke library" action in Media Library
* more upside down videos fixes
* fixed crash if a plugin generated a pledit wm_windowposchanged on shutdown
* fixed crash exploit in in_mod (thanks Peter Winter-Smith)
* fixed various crashes in in_midi when playing invalid files
* made in_midi store its settings in winamp.ini instead of the registry
* fixed error during installation on computers with chinese/oriental regional settings
* removed AOD from installer
* added Shift-R to toggle manual playlist advance
* updated VP6 video decoder to latest VP6.2 code
* fixed crash when launching winamp with very long filenames from explorer
* made registration dialog to appear in Explorer's taskbar when installing pro version
* fixed pledit/video windows showing up at startup when minimized
* modern skins updates :
  - winamp modern skin now uses a 3 state repeat button: no repeat/repeat all/repeat track
  - added appplication desktop toolbars capabilities for layouts, add 
      appbar="left|top|right|bottom" to use them
  - upped maki binary version, improved stack protection
  - current skin version number is 1.2 (this should not change for a long while now, and 
    of course we continue to support 0.8 to 1.1)
  - (very) limited maki debugger (for now you can bring it up with invokeDebugger(); in a 
    script then use 'x' to continue and 'i' to trace into)
  - fixed obscure capture problem with dragging windows
  - fixed rectrgn being forced to 1 in xml xuiobject buttons that are originally imageless
  - fixed hilited state not on after clicking on buttons while the mouse stays in area
  - fixed scripted onEnterArea/onLeaveArea not being always correctly called while mouse 
    button stays down
  - fixed getToken being passed NULL throwing guru
  - fixed clipping of painting within the background's region of a group rather than 
    within the composed region (the one you can change with sysregion)
  - fixed image cache problem when using the same bitmap as a map and a button image 
    parameter

Winamp 5.02:
* added a couple of gen_ml APIs
* fixed gen_ml radio/tv cache clearing after viewing prefs bug
* made gen_ml radio/tv keep old data when updating fails, made it not update when no
  internet is available
* made gen_ml support some new quicksearch syntaxes: "* beck radiohead"
  will list all things matching beck OR radiohead, and:
    radiohead "<lastplay > [3 days ago]>" will show all things matching radiohead
    played in the last 3 days...
* gen_ml option for any/all guess modes
* made SPS support 24 bit samples
* added priority setting for CD ripping
* made CD ripping only support one rip at at time
* added send to -> add to library for playlist (and other) send to menus.
* better media library audio view support for no artist/no album
* fixed enter after info box and popup menus in library
* moved litestep options to be in classic skin prefs
* fixed playlist editor classic redraw bug, made playlist handle mousewheel scrolling while
  moving items better.
* made "EXE" filetype extension non registerable :)
* cleaned up "disable screensaver when video is playing" option
* latest SDKs available (AVS, Media library, new Winamp IPC calls, etc...)
* upgraded to Gracenote CDDB v2 DLLs
* improvements in gen_hotkeys
* upgraded MP3 encoding to LAME v3.95.1
* out_ds now uses winamp.ini instead of registry for settings
* new fix for upside down videos in in_dshow
* added OGM as supported extension in in_dshow
* modern skins updates :
  - optimized region a bit
  - fixed handling of global alpha for unparented layouts
  - fixed tiny bug in keypress flow
  - fixed potential layer capture cancellation issue
  - fixed crash when quickly alternating alt+g and alt+w
  - fixed player not coming up to front when playing a video via external URL click
  - fixed assertion when arial.ttf (or whatever fallback font has been set) is not present in the font directory
  - fixed faulty skin font unmapping sometimes conflicting with fallback to os default gui font
  - added date and version functions to maki
  - added added timerhours="1" to text object to show 1:00:00 instead of 60:00
  - added timeroffstyle 3 and 4 to text object to display "0:00:00" and " :  :  "
  - upped skin version to 1.1 - you MUST use 1.1 if you recompile your scripts
  - updated maki compiler (http://bluemars.org/maki) :
    - added stack protection to maki binaries - upped the binaries version header
    - added self version check in maki binaries
    - non-existing (future) maki functions will not crash the maki runtime anymore, YAY
    - fixed unknown maki functions return values
  - fixed winamp appearing on secondary taskbar with ultramon regardless of true position
  - fixed extraneous invalidations
* new extended jump file dialog (thanks to Darren Owen)
* added basic MP4 AAC encoding/decoding (thanks to Menno Bakker for the help)
* fixed unicode metadata in in_vorbis
* fixed crash in installer code
* removed generation of "badframes.stt" files in VP6 decoder
* <3 farewell Justin <3

Winamp 5.01:
* fixed gen_ml selection bug
* added gen_ml option for no guessing at all
* made AVS and SPS support loop() in user code
* made AVS support megabuf() in user code
* made pro installer not prompt for regkey if already valid
* improved font directory retrieval in gen_ff
* added content rating system in Internet TV's listing
* added bandwidth usage statistic in Internet Radio/TV listings
* made media library guess from filename only when NO metadata found
* added seperate recent items tracking options for files/streams
* made installer better handle installing wa5 directly over wa3.
* added milkdrop docs to installer
* made uninstaller not remove winamp directory if not empty (user is 
  now required to do so manually to avoid people going "oops")
* made installer check sonic px.dll versions and prompt for reboot
  accordingly
* fixed nsv metadata querying bugs
* fixed gen_ml guessing bugs for files with metadata that are not in DB

Winamp 5.0:
* fixed http playlist retrieval issues
* fixed classic skin refresh bug in gen_ff
* fixed editing query while radio refreshing in gen_ml
* modern skin - fixed version detection for skins that use wasabixml tag, fixed unclickable "old skin" msgbox 
* fixed guessing bug in gen_ml
* made agent add icon after explorer.exe crash
* fixed AVS crash on win98 bug
* fixed in_nsv dsp plugin support
* fixed gen_ml -recurse bug
* new Signal Processing Studio DSP plug-in
* fixed out_ds buffer size using crossfade time when crossfade is off

Winamp 5.0rc666:
* fixed potential crashbug in ml
* avs sscope updates, fixes
* modern skins : fixed SHGetSpecialFolderPath on old OSes

Winamp 5.0rc11:
* added colorthemes submenu to options menu 
* fixed AVS bugs, added new texer2 APE
* fixed ML genre combobox low screenres bug

Winamp 5.0rc10:
* modern skin updates
  - fixed coming back from windowshade closes video drawer
  - fixed user settings path assert
  - added 6 color themes (coagulated, peachy, bricks set, rosemary, blueberry and cream, qwayke)
* added media library plugins configuration, support for type column
* latest VP5 decoder, including NSV/VP6 decoder
* disabled hotkeys when hotkeys configuration is focused
* AVS: support getkbmouse() from script. woot.
* AVS: support new text features, including $(title), $(reg00), $(playpos), $(playlen)
* AVS: added (optional) eval code for effect lists
* AVS: experimental SMP support
* AVS: fixed a alpha clamping bug in dmove
* AVS: eval code stats in debug window
* AVS: memory footprint reduction (framebuffer freeing)
* AVS: eval code optimizations, much smaller and faster code (woot)

Winamp 5.0rc9:
* fixed how some very broken databases would set the db recovery into an infinite loop
* fixed info for wa3 skins
* fixed winamp3 upgrading for later builds
* fixed sendto ml playlist when it is open

Winamp 5.0rc8:
* modern skin updates
  - fixed config menu radiobuttons turning off when clicked again
  - fixed unreadable selected list item text color in 2 gamma groups
  - fixed theme list using slightly different colors than ml lists
  - fixed taskbar move syscommand bringing up wa2 main window
* updated avs, faster evallib. makes eval heavy presets superfaster.
* made cd ripping unlock drive and cleanup on exit in middle of rip

Winamp 5.0rc7:
* fixed metrics dialog parenting
* fixed avs Nbuffer stuff, exposed Nbuffers via API (woo hope no more crashy)
* fixed avs memory leak

Winamp 5.0rc6: 
* fixed gen_ml view restoring when "do not load library at startup" checked
* fixed another avs dmove bug

Winamp 5.0rc5:
* made reginfo stored in the registry instead of winamp.ini
* added Ctrl+H to keyboard shortcut list in about

Winamp 5.0rc4:
* fixed drag&drop to main window when AVS is docked
* more advanced title logic tweaks
* fixed error in keyboard shortcuts list in about box

Winamp 5.0rc3:
* updated hotkeys to be tabable
* updated advanced title logic to fix a few issues
* fixed issue when modern skin or gen_ff not found
* fixed modern skin about box when in classic skins]
* new AOD with good uninstall supprot

Winamp 5.0rc2:
* fixed playlist editor status bug
* fixed seh options not being saved
* made installer check for gen_peercast and prompt user

Winamp 5.0rc1
* updated credits
* updated to newer NSIS
* made gen_hotkeys, gen_ml, and gen_ff all use msg registration api to avoid msg collisions
* updated installer to prompt for reboot in certain instances on < win2k
* fixed typo in installer
* modern skin updates
  - fixed options/skins menu issue
  - changed some colorthemes names
  - fixed lack of shift/ctrl + eject
  - fixed shutdown problem with text objects

Winamp 5.0rc0 11/16/03
* fixed crash when subtitles but no video
* added SEH options to avs and winamp for plug-ins
* fixed bug in gracenote TUID and "Now Playing" tab
* added CD locking when ripping
* christophe optimized some in_dshow stuff (not sure if he wanted this shit in here, heh)
* gen_ml recent items limiting fix
* gen_ml info viewer fixes
* SHUT YOUR MOUTH: http://www.firehose.net/~deadbeef/media/music/031115-shutyourmouth.mp3
* modern skin updates
  - final skin drop
  - fixed player taking focus when notifier goes away (again, yeah, i just forgot to check it in :-))
  - fixed resizing / snapadjust issues opening the drawer without showing its content (hole in player) in some cases
  - disabled notifier fade sliders when running on w95/98
  - fixed component editwnd colors (colortheme editor)
  - fixed shade songticker alternate font color not matching bitmap font color group
  - fixed lack of shift/ctrl + next/play/stop/prev
  - fixed system.floattostring ignoring its ndigits param
  - fixed potential crash in text widgets that change display param dynamically
  - fixed locked windows going offscreen (like nonstep avs) made then ignore offscreen since they are locked to a layout that checks its own position
  - added nooffscreencheck="1" for layouts in case offscreen check needs to be disabled for a window
  - fixed assert in region
  - fixed crash color extraction from undefined container
  - fixed crash when not specifying a band parameter to an eqband object
  - fixed buttons onleavearea detection with nonstandard scales
  - fixed notifier not showing minimized when "show in windowshade and when minimized" is on
  - fixed freeform dropdownlists not closing
  - fixed crash when a window is destroyed while moving all windows docked
  - fixed system.playfile (base dir changed, has to be relative to skin in wa5, so filename is tweaked if it starts with "skin\nameofskin")


Winamp 5.0 beta 5 11/14/03
* modern skin updates
  - fixed mousewheel in pledit not responding after context menu popped on frame
  - fixed mousewheel controlling volume when scrolling in now playing ml pane
  - fixed mousewheel controlling volume after clicking on ml titlebar
  - fixed doublesize menu item not disabled when not using scale locks
  - fixed potential crash in colortheme management
  - fixed player getting focus when notifier closes, added nofocusonclose param for containers
  - fixed loading skins that are packaged wrong, with the skin in a subdirectory in the wal
* fixed mouse cursor on popup menus
* updated AVS presets/APEs to good final ones
* updated gen_hotkeys labeling

Winamp 5.0beta4:
* modern skin updates:
  - new skin drop
  - fixed going from opaque on hover to opaque on focus disables autoopacity
  - fixed how the arrow icon on the drawer would not change to reflect the direction the drawer will open
  - fixed notifier not setting winamp to the foreground after restoring it when clicked (added System.activateApplication())
  - fixed closing player with maximize on, now restarts with maximize on too
  - fixed drawer remembering opened drawer size when maximized upon startup
  - fixed closing drawer when maximize on, now drawer keeps maximize state when closed til manual resize and no longer loses old wnd size, will open to maximize height
  - fixed opening config drawer while being maximized losing maximized state and/or saving maximized height, now auto adjusts size to match available space (added System.onSnapAdjustChanged())
  - fixed auto restore on video start if maximized was entered when video wasn't playing (which kinda ruined the point, heh)
  - fixed layout not saving its position when resized from script (ie: clicking maximize button) and reloading to the old pos
  - fixed video overlay repositionning lagging when moving main window from another window (ie, ctrl+shift+move another window)
  - fixed cancellation of drawer animation when using fixed alpha
  - fixed saving unlinked auto opacity setting
  - fixed flickers, paintings slowdowns and leftovers when hosting a skinned window inside the preferences
  - fixed freetype using OS dpi instead of fixed 96 dpi like it was supposed to
  - fixed skins using gradient, polygon, osedge and solid color generated images
  - fixed crash in system.eject() and system.playfile()
  - fixed "component is missing" in a bunch of skins
  - fixed skin crashes due to scriptcore object not found, added fake scriptcore, does nothing (sorry, single core...)
  - fixed crash when switching to skins that do not define the window background color and doesn't lets us extrapolate from a constructed window
  - fixed custom opacity using window's opacity as a starting point (and reseting to it on cancel) when opacity is linked
  - fixed invisible window when loading desktopalpha skin with global transparency on
  - made jpgloading external
  - fixed ctrl+f4 on main window or on pure wasabi windows (with no pl/ml/video, etc, ie: colorthemes) bringing up wa2 window
  - fixed notifier "disable in fullscreen"
  - fixed 0db/-12db not always working
  - fixed eq showing last modern skin eq settings after going back to classic and changing them
  - fixed mmd3 getting chopped off
  - fixed skins getting trapped into a infinite loop because the eq value they set would come back slightly off due to 4 bits of precision lost between wa3 & wa5 eq range, 
      and that would try again and again to set the value based on comparision. made it so that this gap is checked for and if value matches, we send the last hiprecision value in the callback
  - fixed equalizer menu entry being checked after closing config drawer without animation
  - fixed blank notifier when linked autoopacity on
  - fixed switching desktopalpha on a window that previously had forced transparency flag
  - fixed clicking eq button on windowshade not repainting drawer when transparency on and eq wasn't the previously selected tab in config drawer and drawer animation is off (phew!)
* updated a lot of little menu shit
* made better handling of no media in library
* renamed a lot of directories to folders, library to media library.
* disabled drag&drop moving of tree items in media library for other than playlists/views
* made sonic logo in burning link to sonic (well, almost)
* made video view have better column defaults
* fixed changing-systray options while minimized bug
* added simple view editor to library (woot), added support for X:XX times, and a few new operators to querylang
* switched Gracenote submit mode from test to normal
* new Winamp icon
* cleaned up query builder, made time editor external to it so that the simple view editor can use it too
* changed user-agent versions
* improved library length retrieval for legacy plugins
* fixed library adding files to directory list
* updated OLE drag&drop logic to fix library (might have broken other things, but I sure hope not)
* added XP Manifest.xml to winamp.exe
* fixed a channelshift bug in AVS, and made AVS support nifty script help dialogs for APEs
* made ctrl+b, shift+b, shift+z work, added some menu items for some of them.
* made F1 open help, added help menu item to main menu, made help launch browser
* skinned combo boxes in Media Library, made radio/tv resizing behavior better (hides comboboxes when small)
* made agent icon use configured winamp system tray icon
* fixed sendto burner status updates
* made agent use the new icon
* fixed firsttime CD lookup bug
* optimized winamp's load titles on demand logic, made faster
* made winamp prompt before exit if ripping a CD
* made config saving after prefs window closing deferred for better ui response
* improved view editor advanced builder
* fixed manifest
* made ctrl+f1 do about box
* made winamp's internal submenu management more reliable
* made installer support winamp3 upgrading/skin migration
* out_ds no longer changes buffer size when changing crossfading in modern skin, uses max(crossfadetime, buffersize) instead

Winamp 5.0beta4 11/10/03:
* modern skin updates:
  - fixed paint problems when resizing media library up with opacity < 100%
  - fixed flicker in media library list headers when scrolling horiztonally with opacity < 100%
  - fixed potential crash if skin switched many many times
  - gave a better look to gen_ff's about box, made it use wasabi for ttf & script
  - delayed cancellation of forced transparency off (ie, video) by one second to avoid flickering if we're merely switching to a safe transparency mode for a fraction of a second
  - gave log scale to opaque on hover sliders 
  - added System.onShowNotification hooked up to IPC_SHOW_NOTIFICATION so that skins can implement their notifier however they like
  - fixed bitrate/samplerate/channels display sometimes going to 0
  - added System.getSongInfoText()
  - made skin config menu do a real crossfade between pages
  - made skin config menu scroll entire pages of menu items rather than use thinger-like click-n-wait-n-release
  - fixed crash when drawing very big truetype fonts in very small spaces
  - fixed freetype font padding
  - fixed rare region problem when offset(x,y) would do nothing
  - separated default/fallback font from ttf override font
  - added allowmaping="0" to prevent a font from being overriden (ie, the font uses special symbols that are necessary for your design)
  - added auto 100% opacity on focus
  - added font mapper to map any specific font (even a bitmap skin font) to any other specific TTF font
  - fixed tooltips left/right padding
  - added skin info tab in preferences, for skinners to put an about box or preference widgets. when no group is defined,
    we print the data from the skininfo block.
    note: to put a group there, just have a <groupdef id="skin.about.group"/>, the group should be nicely resizable
    to accomodate various dialog size corrections for OS' dpi setting.
  - added display="VID_Info" for text objects to show the same video info string as in classic mode
  - fixed tooltips stealing focus in some rare remaining cases
  - grayed out opacity settings for win95/98
* added bitrate & file size columns to library (you may need to rescan your directories for this info)
* added IPC_SHOW_NOTIFICATION for plugins to ask to show the notification, returns 1 if the skin implements it, 0 if not
* added "show notification" global hotkey


Winamp 5.0beta3 11/07/03:
* modern skin updates :
  - new skin drop
  - fixed winamp3 skins windowshade not being used :
    - prevented use of autoclose="1" in < 1.0 skins (wasn't doing anything in 0.8 but breaks windowshades if used in 1.0)
    - added autoavailable="0" to drawer's wndholder params (should _not_ be used in floating component windows unless you know what you are doing)
  - fixed maddoubleclicks on switch to vis/video spawning undocked wnd
  - fixed vertical componentbucket sizes stuff, added functions to use as custom bucket
  - fixed freetype wrapped text draw
  - removed wa2 skinned cursors in freeform mode
  - removed some wa2 drawing in freeform mode for speed and clarity
  - fixed window position being forgotten when fonts dpi is not 96 (thx dougieha!)
  - added leftpadding & rightpadding params for text objects
  - added auto-100% opacity option, monitors mouse hovering a layout and brings it temporarilly back to fully opaque
  - fixed multimonitor tooltips
  - added multimonitor compliant offscreen detection, brings back to main screen if window is lost, ignored if docked to main window
  - added metadata access for scripts (only to currently playing item) 
  - made color themes auto update to new groups in default theme
  - fixed unwanted window activations
  - fixed region optimizations
  - made grid object build its region (finally)
  - added container.getCurLayout(), container.close()
  - added noparent param for layouts (excludes from the minimize/restore window group)
  - added forcealpha param for layouts to prevent screen burps when changing often transparency (keeps layered flag if alpha=255)
  - added layout.getDesktopalpha(), layout.istransparencysafe()
  - added system.isminimized(), system.minimize(), system.restore();
  - added system.getplaylistlength(), system.getplaylistindex();
  - fixed layout.setalpha()
  - fixed changing display param on text objects after init
  - made random button toggle random instead of switching to a random preset, changed avs & milkdrop accordingly
  - added submenu to views in all 3 playlists popup menus
  - fixed keyboard shortcuts not being redirected to winamp in some circumstances (ie, titlebar click in library)
  - fixed keyboard cancelling capture when dragging (ie, ctrl+alt+dragawindow)
  - newer skin drop! with new config menu and crossfader
  - fixed isDesktopAlphaSafe() crashing in w98 (grrr) and isTransparencySafe not taking everything into account, fixes notifier in win98
  - fixed onplay being called instead of onresume in script
  - added notification of pause / resume
  - fixed double click on songtitle popping a non-responding dialog box
  - fixed double click in songtitle not cancelling text grab
  - added fullscreen flag for vis to send to winamp so that script can query if something (video or vis) is fullscreen, modified avs & milkdrop accordingly
  - linked auto100% opacity when layouts opacity is linked
  - added link all windows opacity (and auto100%) & scale, added custom opacity dialog
  - made auto100% hold time configurable
  - made another mode where scale lock is just ignored, and everything is locked
  - fixed notifier being in the menu (added nomenu param to containers)
  - fixed forced-auto100%-opacity on window request (ie, video/milkdrop)
  - fixed docking and moving the notifier leading to crash
  - fixed opening scale menu in notifier and clicking ok when notifier is gone crashb
  - added distance to window for auto100%
  - added configurability of fadein, hold, fadeout time for auto100%
  - disabled video/vis drawer when not in 100% opacity for microsoftish reasons
  - added Layout.isLayoutAnimationSafe() for scripts to do the same
  - made font renderer svc load early, fixes a crash when using <truetypefont /> in gen_ff's system xml
  - added detection of hover on winamp's dialogs & menus for auto100
  - fixed (00:00) in title when playing streams
* added user-definable global hotkeys (gen_hotkeys)  
* added font override combo for pledit
* added "recent items" view to media library (independent of main library data -- tracks files, streams, etc)
* added column customization in library (right click on columns header)
* added comment, play count, last played, last updated, and ratings columns
* added ratings setting context menu in media view
* made the library detect alt+3 tag changes from within winamp and keep DB up to date
* added query editor, whoohoo
* added option to use pledit font in trees and views, then justin fixed it ;)
* updated to new sonic SDK
* fixed mini info viewer bugs 
* made winamp use filename guesswork even when library isn't open for script access and title 
  formatting (of course, only if no metadata is in the file)
* made library info viewer have meaningful info on artist/album clicks
* made library never add .cda files
* created general API so people can use the sendto menu in ml plugins and in other plugins
* added ML DB API, and ML plugin adding API for other kinds of plugins
* added sendto menu to playlist editor context menu
* made nsv/mp3 tag editting not increment play count
* added data track checks in CD ripping
* added spacebar shows current playlist item in playlist editor
* made ml's recent items optional, and moved config for it to prefs (added option for how 
  many days to keep items in list, too)
* made ml's internet tv/radio items optional.
* made library DB file updating more robust, and added a ton of code to recover corrupted DB.

Winamp 5.0beta2 10/23/03:
* modern skin updates :
  - new skin drop
  - woo francis owns, and fixed keyboard bugs
  - fixed alt+f4 from video wnd & pledit
  - fixed resizing cursor in popups
  - fixed add to library parenting window to main window rather than to library
  - fixed switching to vis while video is playing
  - added checkmarks to scale/opacity menu
  - fixed avs fullscreen complaint when video is there hanging
  - fixed resizerect docking to viewport for snapAdjusted wnds
  - fixed slowdowns loading big playlists in mmd3
  - added redock after drawer open/close
  - gave modern skin default positions for main wnd/pledit/library
  - added popup menu on song title text
  - fixed how menus would overlap menubar buttons when skin was at the bottom of the screen
  - added "animate config drawer" in skin option menus
  - fixed saving/restoring of classic main window and eq status, and classic pledit windowshade and size
  - fixed showing classic skins at startup when loading modern skin
  - even newer skin drop
  - added "temporary" to scale menu so that this locked scale thing is a bit more obvious
  - added "pe_info" xml text display string for pledit selected/total length (not yet in skin)
  - added dsound ipc for crossfader buttons/sliders support
  - added vis menu action ("vis_menu"), made modern skin's button configurable (menu/config)
  - added localization support in gen_ff
  - added bitmap font override to ttf, added pref page with font list & scale overide
  - added altfont, altsize, altcolor, altprettymucheverything for text objects, so that
    skinners can make their skins ttf friendly, added "use alternate fonts" in fonts pref tab
  - added checkbox for using operating system font rendering
  - gave a few fontsizes to bitmapfont text objects so overrides aren't all the same size
  - fixed crashbugs when not finding ttf fonts
  - fixed empty playlist when starting with previously windowshaded playlist in classic mode but no xnf data
  - fixed crash when trying to update stuff while switching skin
  - fixed crossfader time going back to 0
  - added right to left ttf rendering
  - fixed layouts jumping on the screen when changing truetype font override
  - updated to freetype 2.1.5, fixes crash, #ifdefed out some unused stuff from it
  - fixed ctrl+w + alt+g guru
  - fixed alt+tab while resizing player
  - fixed player leaving a resize trail when aborting resize above autorefresh-on-alt+tab windows
  - removed small kerning hack due to freetype 2.1.5 having much better native kerning
  - fixed equalizer xnf entry getting duplicated over and over
  - fixed small leak in font loader
  - fixed font engine not reloading a ttf font after switching to win32 font renderer and back (and thus, using the override font, which also serves as fallback)
  - adjusted some ttf rendering paddings
  - added ability to not override bitmap font with ttf or use altfont on 7-bits character strings
  - fixed disabled widgets states
  - fixed typo in about box :)
  - added ctrl+tab / ctrl+shift+tab to cycle thru windows
* made playlist showing deferred so startups looked cleaner with modern skins
* fixed crash on skindir change in prefs
* added "adding to burner" status window when using sendto/drag&drop to burner, for reassuring
  status
* added rescan in background menu item to library menu
* added "add folder in background" checkbox to "add folder" in library
* added scan on startup library option
* christophe's now playing updates
* fixed manual playlist advance w/ repeat
* fixed CD burning view and skin switching bug
* fixed burning when WAV writer is configured to not write WAV headers
* switched to new Gracenote ID
* fixed "return" key in ml's info editor
* added left mouse click on disabled edit boxes in ml's info editor
* better burning error handling (shows the burning status window to easily view the error)
* better mini-info-viewer when no internet handling
* made winamp's open directory recurse checkbox nicer looking
* avs doubleclick (fullscreen vs config) option in fullscreen options
* avs alt+f4 closes winamp instead of loading preset
* milkdrop config while running now shows help
* added new avs default presets
* fixed installer dual-winamp-launch bug
* fixed gen_ml bg scanning error problem
* optional screensaver disabling for video, fullscreen or not. now with optional mode that works
  even if winamp is not active.
* slight avs window reorganization
* made modern skin extracted by default, for speed
* improved config dialogs for aac/mp3
* made info viewer activated by button instead of slider 
* made internet radio/tv page handle resize better (search doesnt get screwed on small windows)
* cleaned up some labeling places
* cleaned up ripping and burning UIs more
* fixed library prefs radio buttons
* added Gracenote TUID retrieval in "Now Playing" tab in ML
* cleaned up ML playlist editor buttons, added burn button
* added wait for blank media dialogs for burning
* made bookmarks support drag&drop more and sendto.
* made it so you can't remove/rename modern skin
* added option to add burned CDs to local CD DB

Winamp 5.0beta 10/13/03
* modern skin updates :
  - fixed win98 crash with desktopalpha skins
  - fixed pledit jumping on top of main window when docked and interacting with config drawer
  - fixed avs hiding main window when docking to editor
  - fixed vis gammagroup filtering
  - fixed bgr color for pledit scrollbar background in v1.0 skins
  - fixed rare crash on skinswitch
  - added timers resolution autodetection
  - added configuration of text scrolling speed
  - added vis_cfg action to toggle vis cfg window via button
  - fixed config drawer tabs moving the app when not selected
  - added enable docking checkbox and docking distance editobox in prefs
  - added tooltip checkbox in prefs
  - fixed tooltip stealing focus from popup menus
  - added support for noresize flag in embedwnd so that it spawns the right container
  - added notransparency flag for embedwnd, made milkdrop use it
  - fixed potential aot reset by embedwnd (ie, milkdrop)
  - fixed slow text ticker, made it use timerclient_getSkipped to have consistent speed regardless of timer resolution
  - added timer resolution in prefs page
  - added link ratio & alpha in prefs page
  - fixed empty popups in pledit menubar, commandbuttons and ml menubar when no playlist or devices are available
  - fixed "mono" display when nothing playing, made songinfo update faster after clicking play
  - separated link position & link width for main winshade window, changed default to link all
  - removed move="1" for song title display on main window normal and shade modes
  - fixed click on beatvis that would sometime fail to toggle active status
  - added gammagroup xml param to vis objects
  - made switching to windowshade open undocked video & vis when video is playing or vis is visible, docks back when coming back to normal mode
* made library able to update info on files that dont support tag writing when tag writing is checked
* fixed burning bug when using certain .WAV output settings
* enabled burning on multiple devices simultaneously
* made Winamp check to see if AVS or milkdrop is running fullscreen before starting video playback, and remove
  fullscreen if necessary
* made AVS and Milkdrop check for video playback before going fullscreen (milkdrop uses fake mode, AVS complains)
  (to avoid DirectDraw crash)

Winamp 5.a10 10/10/03:
* fixed library's playlist buttons
* cleaned up prefs for steve some
* fixed crash bugs in AVS, added new AVS effects from Unconed and Tom Holden
* made doubleclick in AVS go fullscreen
* made AVS autodetect video modes for fullscreen if necessary
* updated to latest veritas SDK (should prompt for reboot if necessary now)
* new milkdrop that integrates better, and fixes bugs, and is smaller
* fixed tagz '?' lameness
* modern skin updates :
  - fixed aot changes not being detected
  - fixed elapsed/remaining toggle not being forwarded
  - fixed right key in menubar when menu item selected is a submenu, fixed left when in a submenu, fixed right after hovering on an submenu item, phew!
  - fixed left/right keys seeking while in a menubar
  - fixed guru due to custom checkbox accessing nonexisting layouts because they are now dynamic, made them use configattributes
  - made vis & video open undocked when in windowshade mode

Winamp 5.0a9 10/08/03:
* modern skin updates :
  - fixed starting modern skin when winamp is minimized (or reloading winamp with modern skin when it was minimized on exit)
  - added Vis_FS action
  - added menubar keyboard shortcuts
  - made winamp ask the skin about *any* key it receives so that script can trap (and prevent) them
  - added left/right keys for menubar navigation
  - fixed avs flicker when spawning & closing via menu or keyboard shortcuts
  - added guid for colorthemes pref page ({53DE6284-7E88-4c62-9F93-22ED68E6A024})
  - fixed keyboard script hooks
  - added "equalizer" to popups, automatically opens the drawer and switches to the tab
  - added modern skin submenu to main popup menu/options
  - added attrib page for adding items to View menu via script (also show up in main popup)
  - fixed auto move of docked layouts when switching to windowshade when original layout has snapadjust values
  - added action PE_ListOfLists for winshade playlist editors
  - added about box guid for lightning bolt click ({8DDA9D48-B915-4320-A888-831A1D837516})
  - added unlink="1" for layouts to remember their own position/size regardless of linkwidth/linkheight
  - added windowshade for main & pledit, whoohoo Sven!
  - fixed checkmark for container entries in menu
  - added automatic discarding of unused bitmaps in memory, drops usage by 2 to 7mb (depending on skin) when not interacting with the ui
  - fixed huge leak in ttf rendering, that one was leaking 300k/s when the song title was scrolling ! uh oh...
  - fixed small leak in xmlparser
  - fixed parsing of groupdefs in the middle of dynamic containers
  - fixed small leak on skinswitch
  - fixed small leak in gammamgr
  - reduced memory usage by ~3mb when using winamp modern skin.
  - fixed shutdown sequence
  - fixed drawer locking up in closed position after detaching both windows via the menus
  - fixed vis or video poping up when clicking detach menu option while wnd is hidden
  - added option to bypass user defined drawer direction when window is going to get partially hidden after opening the drawer
  - added ability to set cfgattribute value "-" to make a separator in the custom skin option menus 
  - added user option for drawer direction
  - added reversed drawer, heehee
  - added guiobject.reverseTarget() to move x/y values according to w/h values so that a drawer moves the opposite direction (ie, increase w/h in a targettimer, call reverseTarget and instead of growing to the right/bottom, the object will grow to the left/top - works on layouts!)
  - fixed weakness in assessing visible states 
  - fixed drawer not remembering size after user resize
  - added open from library in pledit lists submenu
  - added "manage playlists" in pledit lists submenu
  - fixed seek on doubleclick in openfile box
  - fixed pledit disapearing on winamp startup
  - fixed minivis stopping on desktopalpha toggle
  - fixed some drawer issues
* cd burning view:
  - added item moving stuff
  - burners default to burning view when no cd present
  - added burning view auto refresh
  - added 44khz resampling
* made good generic title formatting system, that'll use library data, id3 tags, vorbis tags, cd info, etc.
* in_dshow: added buffering status when playing streams
* added skin rename/remove support
* made ripping to WAV file when using a ACM conversion to generate proper files
* in_nsv: added PCM support
* fixed random skin support
* fixed user info dialog multiinstance issue
* added gracenote tuid retrieval in library's mini infobrowser

Winamp 5.0a8 10/02/03:
* big modern skin updates (as usual)
  - docking/undocking support and drawer fixes
* library has leet audio view searching now
* mucho bugfixes, yo

Winamp 5.0a7 9/29/03:
* big modern skin updates (woo!)
  - fixed opacity related repaint flicker when hiding video
  - added modernskin custom options preliminary submenu 
  - added smooth scroll of the video/avs drawer
  - fixed modernskin videoavs.m bugs
  - fixed focus problems with avs in the main window
  - changed "Media Library" to "Library"
  - changed "Freeform" to "Modern"
  - fixed wndregion problems when heigth/width of a group is zero
  - fixed wndregion problems when showing/hiding objects
  - fixed repaint problems
  - fixed bug with playlist editor background color
  - added font size correction
  - added lite bold (bold="2") which looks similar to old antialias="1" on non bold, so for skins backward compatibility, bold + old antialias = lite bold
  - more color interpolation fixes
  - made skin menus use win32 menus
  - fixed autowidth/height from text with bold/italic attributes
  - added system.getidealvideowidth/height();
  - added colorthemes_next and previous actions
  - added actions for pl/video/avs command buttons
  - made video follow its rect without 250ms delays
  - fixed checkmark for elapsed/remaining in options menu
  - added lock in scaling menu
  - added nohscroll="1" to themeslist object to hide the scrollbar
  - fixed gammagroups for text widgets
* more prefs overhaul to make steve happy
* cd burning fixes
* cd ripping crash fix
* other fixes/etc
* gen_ff :


Winamp 5.0a6 9/25/03:
* followup to 5.0a5:
* modern skin fixes (yay francis rules):
  - fixed HUGE doublesize by always resizing back the huge width or height to the screen max
  - fixed safe transparency autoswitching
  - fixed render ratio problems when opening embedded window in already scaled window
  - added control menu to app context menu
  - implemented ff control menu
  - added layout snap adjustment
  - added System.switchSkin script call
  - fixed initial focus to main window
  - added eq commands from menubar
  - added radio/tv in menubar
  - fixed pe menu / open from library only showing the playlist rather than playing it in the pe
  - made PE_File context menu load playlists even if ml was never shown
  - added context menus for the player controls
  - added elapsed/remaining hook for time displays
  - fixed ml/pl button not lightning up when ml/pl is showing
  - added checkmark for "Main Window" when the main container is visible
  - improved color interpolation for wa3 skins
* fix to ripping speed selection crash bug
* updated mp3 codec selection on unreg stuff (to revert back to old codec)
* burning ui fixes
* installer fixes [workarounds for now too]

Winamp 5.0a5 9/23/03:
* very alpha version of new modern skin, lots of gen_ff updates
* new install process (Thanks kichik for the help)
* cd burning
* better AAC time updating support
* mp3 ripping (with winamp pro regkey)
* sendto menu in library
* big AVS updates (2.7pre3 or so? forgot to update the ver#, but this one is newer than
  anything other as of 9/23)
* directory autoscanning for library (woo)
* more! I forget it all...

Winamp 5.0a4:
a4: mostly cosmetic update:
a4: fixed library/pe in wa3 mode in 16bpp mode
a4: new splash screen
a4: updated credits/about box stuff
a4: added good in_nsv about box
* .wal support in winamp.exe
* changed ripping filename specifier to <artist> etc
* minibrowser moved to gen_ml
* made empty media view have some crappy text + add directory button
* down arrow in library search now go to results
* veritas SDK integration for CD ripping/playback
* huge preferences makeover
* mini-context-info stuff in gen_ml (complete with internet checking)
* made bitmapped font in winamp off by default for better int shit
* uninstall plug-in support
* changed allow multiple instances behavior to be better (always off
  when playing/enqueuing files)
* made bookmarks viewer editor in library
* made library support drag&drop for adding directories
* made library have more options for adding files metadata
* made library metadata updating faster
* tons of wa3 skin love
* about box for AAC stuff
* made wa3 pledit use colors and better scrollbars
* bugfixes in gen_ff
* fixed little gfx bug in fullscreen video playback on multimon
* more!


Winamp 2.95 (never released):
* startup with hung winamp process in background fixed (opens new instance)
* CD ripping support in media library
* Preliminary AAC playback support added to in_mp3.dll
* ryan fixed shuffle again
* minibrowser ctrl+l fix
* media library: lots of bugfixes
* media library: listener count in internet tv/radio
* media library: query playback mode preferences
* media library: skinnable list/treeview selection colors
* nsv: subtitle bugfixes
* nsv: more buffering options
* nsv: shoutcast metadata support
* nsv: better invalid bitstream handling
* nsv: better display options
* nsv: new ASYN aux chunk handling.
* nsv: support for new extended TOC with frame-accurate seeking
* video: overlay fixes on 556 and other unusual modes
* video: drag&drop URL to video window now works.
* video: subtitle fixes.
* video: support for alt+enter and alt+f4 to leave fullscreen
* cdda: bugfixes
* avs: evallib | and & operator fixes
* in_vorbis fixes/updated libvorbis to post-1.0 cvs
* in_midi fixes

Winamp 2.91:
* fixed an incorrect vis color
* fixed shuffle; now, when you start winamp w/shuffle on, it returns 
                 you to the song you were at when you exited last time
* made winamp not crash if you close it while a file info dialog is open
* fixed jump dialogs when using language packs
* fixed tooltip in lightning bolt
* made video window on autoclose not stop if configured to do so
* made in_mp3 have options for adding tags from ml
* fixed a bug in in_wm
* library: made library refresh properly on add/compact/etc
* library: fixed a library win9x view issue
* library: fixed shift+enter in media library tree
* library: added "Explore item folder" in library's media view
* library: made internet radio/tv display msg when reload is blocked
* library: added "Physically delete file" in library's media view
* dshow: added config dialog (filetypes)
* dshow: added option to vertically flip WMV videos (for machines with old WMV
         codec installed)
* dshow: added file info box
* dshow: fixed issues with widechars
* dshow: fixed bitrates displayed
* dshow: added 32 & 64-bit audio support
* nsv:  fixed title updating (playlist flicker) bug
* nsv: made nsv info box show filename and basic info
* nsv: made nsv use less cpu on [p]rebuffering
* nsv: fixed mp3 decoder's eating of the end of nsv file
* nsv: added AAC decoding support
* nsv: fixed vis on audioless nsvs
* put AOD in all installers (opt-out always)


Winamp 2.90:
* hot new default skin, done by none other than the evil robot turned good, Steve Gedikian
* added integrated full featured video support (NSV and DirectShow (AVI,ASf,MPEG,etc)) 
* added library (complete with media database, shoutcast listing, playlist editing, 
   CD listing, mass tag editting, plugin API for portable devices, and more!)
* updated Winamp's window docking code to be more robust/extensible
  - made AVS dock use this new API
* updated PCM equalizer with code from 4Front Technologies/George Yohng. Quality is a lot better.
* updated equalizer default skin to show the true +12db/-12db range (the 20db was a veeery old typo)
* a ton of new WM_WA_IPC API calls.
  - general purpose plugin window support
  - extended metadata system for getting more than just title/length of items.
  - lots of exposed features via IPC
* updated to PP's latest input and output plugins
* focus/Z order change on window close related bugfixes
* added track numbers and song lengths in HTML generated playlists
* removed all ATL code, shoved EXE size by 20kb :)
* added digital audio extraction in in_cdda.dll
  (needs WNASPI32.DLL under Windows 9x/ME)
* added Alt+M shortcut for minimizing Winamp
* added Ctrl+(Keypad +)/Ctrl+(Keypad -) shortcuts in playlist editor for changing font size
* fixed stop after current menu item trash related bug
* added ultravox support for in_mp3
* made in_mp3 not display 'unknown X' for empty id3 tags
* installer uses leet new NSIS 2.0b3
* improvements to the setup process
* made the keep on screen code multimonitor smart and better
* fixed & error in tooltips in winamp and winampa's systray icons
* and TONS more! (new SDKs will be posted soon.)

Winamp "Classic" 2.81:
* updated to PP's latest input and output plugins
* in_mp3 now doesnt continue to play on output plugin error.
* smaller installers because we use msvcrt.dll now
* fixed bugs relating to files with ~ in their names.
* doublerightclick in credits makes for fullscreen credits
* more bugfixes (including a fix in the version update notification checking)
* updated installer to have nicer error messages.
* made systray icon update if explorer restarts
* and more (muahaha)!

Winamp 2.80:
* fixed drag&drop from open file dialog related bugs
* made CDDB support better handle not-found CDs/lack of CDDB installed.
* update to CDDB ui (bugfix)
* new splash screen
* minibrowser security fix
* updated winamp agent to support both winamp 2.x and 3.x
* included PP's hacks for slightly better unicode filename support
* in_wave support for floating point .WAV files fixed
* better win9x compatibility for DirectSound
* waveOut made skip less
* some in_mod per-file fixes
* OGG Vorbis support for Standard and Full installs.
* CD support back in lite installer.

Winamp 2.79:
* upgraded unzip/decompress support to zlib 1.1.4, for big security fix
* improved multiple instance detection code/opening many files from explorer issues
* winamp agent tooltip improvement
* fix to id3v2+unicode support

Winamp 2.78:
* minibrowser fixes
* cddb2 support
* updates to mod, midi, and wav support (from the wonderful PP)

Winamp 2.77:
* mb.ini skin support (Winamp/MBOpen)
* added page and slider for 'shuffle morph rate' to Preferences so you can 
  control how much the playlist morphs (mutates) each time it cycles 
  through.
* PP's ACM disk writer output plug-in instead of the classic one
* PP's WAV/VOC reader (Which is apparently so much better, but we will see)
* included new in_midi and in_mod (yay)
* made playlist editor automatically size down when necessary (on startup)
* made drag&drop playlist URLs work
* made alt+delete work again in playlist editor
* made winamp.exe and winampa.exe both much less likely to fudge HKCR/.
* fixed drag&drop in vis areas
* made Winamp handle language packs that lack strings and/or dialogs better
* made physical file remover ask you for every file, to prevent disasters
* fixed issues with using a large number of input plug-ins and extensions in 
  open box (I think)
* fixed a small "bug" in the id3 editor of in_mp3
* fixed the frame count bug in id3 editor of in_mp3
* made general purpose plug-in uninstall capability.
* new hyper-leet desktop icon on new installs of full version.
* removed Mjuice support from full version.
* tinyvis 2001 v2.04
* AVS includes experimental fullscreen overlay mode.


Winamp 2.76:
* ryan fixed shuffle!
* christophe added IE URL drag&drop capability
* faster FFTs for vis on WAV/CDDA playback
* fixes RealPlayer's .xpl association bug
* AVS 2.5 (new effects, speedups, smaller presets, etc)
* TinyVis 2001. Includes fast, highly trippy "Random Intelligent Visualization".
* Peter's latest and greatest MIDI plug-in

Winamp 2.75:
* avs 2.4.9 (interface improvements, speedups, new dynamic movement effect (yay!))
* made skin installing do better renaming (removes [1], etc)
* some new sample avs presets (thanks to Zen-X and Marco Muraca, Frank Nagel)
* MASSIVELY optimized directory scanning and removed multi-add bugs
* fixes to in_mod and in_midi.
* fixed some NT/2K uninstall issues.
* updated winamp agent with full color icon
* temporarily removed in_asfs from full distribution (security issue)

Winamp 2.74:
* fixed vis shutdown related bugs (message pump is run while waiting for safety)
* cleaned up some startup code
* fixed layer 2 i/s bug in in_mp3
* fixed HTTP/1.1 + Apache CGI issues in in_mp3.
* improved HTTP auth support in in_mp3
* updated to new in_midi version (go PP)
* new AVS with Overlay support
* made uninstall use NSIS's uninstaller

Winamp 2.73:
* smaller main winamp.EXE
* new AVS version with larger interface
* seeking for HTTP/1.1 streamed MP3 files
* improved minibrowser functionality
* updated versions of MOD and MIDI plug-ins (thanks Jake and PP)
* made out_wm smaller (32k->7k)
* updated to newer, more efficient installer (1.1o)
* fixed one cdda related bug

Winamp 2.72:
* stupid in_mp3 fix (for lame encoded files)
* updated directmusic/midiOut plug-in (Thanks to Peter Pawlowski)
* updated mikamp plug-in (Thanks to Jake Stine)
* made Winamp Agent smaller, use less memory, not interfere with ScanDisk, etc. 
* fixed some skin related bugs (main.bmp is no longer ever reloaded)
* fixed cursor bugs - cursors are now loaded all at once (makes for slightly
  slower skin switching, but should make things more responsive)
* made zip skin loading more reliable (and slightly slower)
* small avs updates

Winamp 2.71:
* new directmusic/midiOut plug-in (PP's)
* mikmod update (we love you Jake)
* avs: optimized fullscreen 32bpp->Xbpp (not full support yet)
       better resizing code, multimonitor support
       many stability improvements, opts to evaluation compiler
       new effects, of bugfixes
       avs minimize modes work right (mostly)
* in_cdda: reduced plug-in size by 30k.
* out_wave: made writeall logic better and less problematic
       altvol mode in no longer fudges with global volume.
* in_mp3: improved mp3 decoder sync (byte level sync, better checking)
          fixed id3v2 rare writing bug
          fixed in_mp3 visualization bug
          made highest the default text for in_mp3
* made shuffle not reinit shuffletable on add/remove, it adapts randomly
* got rid of http:// checking for file retreiving.. http is assumed
* made tooltips and hotkeys for demand/load/play in preferences
* made 12k fullscreen visualization plug-in for all installs (woo)
* fixed F5 redrawing stuff it shouldn't bug
* fixed moving a file in the playlist and then using shift to select
* fixed / in IPC issues (i.e. winamp.exe http://url now works all the time)
* fixed the generic eq slowdown on silence, made more accurate
* fixed vis plug-in installation issues
* made workaround for bug in in_mjf.dll
* a few other fixes I forgot to log

Winamp 2.7:
  * mp3 decoder: better tag editor, bugfixes
  * mod decoder: too much to list. much revised. www.divent.org for more info.
  * much improved CDDA (Faster, less crashy)
  * waveout output plug-in bug fixes
  * new directsound output plug-in (very charming)
  * many optimizations and bugfixes to AVS - this version is quite fast.
  * faster playlist loading, faster playlist editting on large lists
  * windowshade visualization now has spectrum analyzer instead of (crappy)
    VU meter.
  * improved that old issue of what happens when you delete the playing file 
    in the playlist.
  * made credits less problematic (and more time based, less frame based, no more crashing)
  * made multiple-instance handling handle running with different command lines better
  * return of classic demo.mp3
  * sped up exit process some
  * many other small fixes and refinements
  * nsis 1.0 installer (http://www.nullsoft.com/free/nsis/ for more info)

Winamp 2.666:
  * spiffier credits in about box
  * new mp3 input plug-in
    * streaming improvements (now much less intrusive)
    * fully ISO compliant decoding
    * ID3v2 support
    * even more
  * AVS 2.1 . New blitter/movement filtering, MMX optimized, new presets.

Winamp 2.65:
  * fix to ex-m3u bug/security hole
  * improved mp3 http streaming dialog (no longer upsets AVS, etc)
  * optional aol icon in full version

Winamp 2.64:
  * fix to proxy support for mp3 streaming
  * dsp plugin fixes
  * justin can't code

Winamp 2.63:
  * language pack improvements/cleanups
  * giant (2000+) skin archive bug fixed
  * promotional offers on install
  * streaming improvements (authentification, proxy authentification, dialogless
    streaming when winamp is not active, content-disposition usage, etc).
  * minibrowser start page now live if inet connected.
  * return of out_wm (WMA writer) -- lets you transcode your WAV/MP3/MOD/etc
    files into WMA!

Winamp 2.62:
  * Generic dialog processing message loop so now TAB/etc... works in plugins dialog windows
  * Fix to Mjuice (memory leak that caused the full install to puke after many hours)
  * Winamp Visualization Studio updates.
  * Installer bitmap updates
  * Installer terminology changes

Winamp 2.61:
  * In accordance with Microsoft's license agreement, we no longer allow you to 
	use DSP plug-ins or alternate output plug-ins when playing WMA files. 
  * Installation now gives you more options, cleaner.
  * Some mixed block DCT and Antialiasing fixes to Nitrane.
  * Support for .wsz files in your skin directory as well as .zip files.
  * Fixed: gdi leak when switching skins
  * Fixed: gdi object leak when using Winamp systray icon
  * AVS 1.5a6 (coming soon, 1.50)
  * fixed: make the mouseover on install listbox not, err, mess up at weird screen locations
  * fixed: the install screen that comes up always when no net connect available.
  * fixed: bookmarking from explorer should be less nasty
  * updated: uninstall should be more reliable
  * attempted fix: bookmark add/prefs display corruption bug

Winamp 2.6:
  * Massively improved CD audio support complete with menu option to play CD
  * New splash screen (smaller) and about box effect.
  * Removed unused links stuff in about box
  * Improved Jump (to file) dialog (hit the J key)
  * Bookmarking system
  * Fix to mp3 plug-in. Now won't stop after failed shoutcast stream.
  * Updates to URLs used in player for web site integration
  * Winamp Agent (can monitor file types, and restore them)
  * Better Netscape/IE integration
  * Updated MJuice code
  * Updated AudioSoft code
  * Uninstall icon in start menu now has own icon
  * New SuperPiMP installation system

Winamp 2.5d:
  * New MJuice code
  * Cleaned up CDDA plug-in and fixed a few bugs

Winamp 2.5c:
  * Full version has MJF support
  * Fixed icon assignment bug
  * Added option for old-school playlist editor buttons
  * Fixes EQ volume setting bug
  * Removed playlist editor child options
  * Vastly improved window stack positioning code
  * Fixed some rare and strange docking bugs

Winamp 2.50:
  * Winamp is now freeware! Thanks to all who have previously 
    registered, your support is really appreciated!
  * Skin selection menu in main menu, browser in preferences
  * Builtin visualization settings are now in preferences
  * Two streaming-related bugfixes to in_mp3.dll
  * Added streamed-file saving to in_mp3.dll (no shoutcast saving, sorry)
  * Added extended-M3U/PLS support (files include title and length info)
  * Improved in_mp3.dll's frame sync code
  * Better multi-byte character set support
  * Numerous playlist editor bugfixes, and refinements
  * Fixed some default skin images
  * Fixed some leak and GDI issues (thanks, BoundsChecker)
  * Fixed some leaks in in_cdda.dll
  * Restructured some internals of Winamp for bitrate reporting for speed
  * Added recent stream list to open location box
  * Automatic IE integration for SHOUTcast
  * Fixed a bug in out_wave.dll
  * Updated AudioSoft plug-in
  * Final WMA support for full version

--------------------------------------------------------------------------

Winamp 2.24:
  * WSZ (Winamp Skin Zip) handling (simply open a .WSZ file in explorer 
    to have it installed)
  * Two distributions (one with WMA and ASFS, one without)
  * Better equalizer presets
  * Better shuffle logic
  * Better docking code
  * Better support for invalid ID3v2 tags (for people putting invalid tags on)
  * Minibrowser optimizations
  * Fixed occasional random crashes from 2.23 

Winamp 2.23:
  * Nitrane 1.60 MPEG audio decoder with MMX and 3DNow! acceleration
  * MikMod module decoder plug-in version 1.3
  * Self-destructing streaming dialog boxes
  * Equalizer presets included
  * Cosmetic fixes

Winamp 2.22:
  * AudioSoft ASFS Support
  * SHOUTcast 1.1 (final, released) support
  * WMA fixes
  * Lots of bugfixes

Winamp 2.21:
  * WMA support fixed
  * MP3 decoder bugfixes
  * Vastly better DirectSound output
  * Other bugfixes

Winamp 2.20:
  * Windows Media Technology 4.0 (WMT4) input/output support
  * All new better sounding, industry standard Fraunhoffer MP3 decoder
  * Generic PCM EQ that works on most formats (WAV/XM/MOD/IT/VQF/AAC/etc)
  * Recursion in open directory dialog is now optional
  * Windowshade mode for Equalizer
  * Improved CDDA support
  * Minibrowser improvements (new start page, etc)
  * New version checking
  * Fixed evil beeping bug
  * Fixed vis/dsp plug-in directory bugs
  * Fixed de-registration problem. 
  * Fixed a few small bugs

What's new in Winamp 2.10:
  * New preference system (yay!)
  * New install screen stuff (with easier configuration)
  * Improved CDDA plug-in, with auto-play
  * Improved MPEG audio decoding
    * Blip reduction
    * ID3v1 URL Comment support
    * Shoutcast URL Browser support
    * Shoutcast 1.1 title streaming
  * Improved MOD/XM/IT rendering (64 bit mixing, sample declicking, etc)
  * Totally new output driver (faster and more compatible)
  * Language package support
  * Windows font support w/ International characterset capability (optional)
  * Better filetype registration (with options to register on start, etc)
  * Desktop Icon and Quicklaunch adding
  * Customizable DSP/Vis plug-in directories.
  * Playlist editor has more intuitive moving
  * Winamp Browser 
  * A TON of bugfixes (if you've been having GDI errors this should fix)

What's new in Winamp 2.09?
  * Fixed stupid hanging bug in CDDA support 
  * Fixed retarded Windows-making-the-window-too-high-after-awhile bug.
  * Fixed clear-playlist-then-seek bug.
  * Fixed Nitrane's invalid-genre %6 bug.
  * Added full Xing VBR support to Nitrane. Seeking and time estimation
    work perfectly.
  * Preliminary ID3v2 support (tag is skipped reliably)
  * Improved Directsound output (Thanks to Leif Claesson)

What's new in Winamp 2.08?
  * Stupid VC++ 6 screwed up my PropertySheets. Crashed on some systems.
    Fixed (as far as I can tell, let me know =).
  * Fixed a stupid CPU consuming bug in Nitrane
  
What's new in Winamp 2.06 (the final release of 1998!)?
  * Built with VC++ 6 and VC++ 4.2. Faster and smaller (well, we hope)
  * Installer now prompts to use old config/fresh config
  * Uninstaller only will remove Plugins\ and Skins\ if they are in the
    Winamp directory (i.e. if you have a giant skin directory in another
    location it won't remove it)
  * Added bar analyzer mode to built-in vis (woo!)
  * Made .pls playlists streamable
  * Info-reading on demand mode, supplements info-on-load
  * Made http:// default in open location box
  * Better directory and drive adding support (you can now do 'G:\' in 
    the open location box to play an audio CD, for instance)
  * Fixed a slight alignment bug in playlist editor
  * Nullsoft Visualization Library!  (wVis 4.1+NS Fullscreen Vis)
  * Included experimental gapless output driver (rocks the casbah)
  * Improved DirectSound output driver
  * Made some mods to the waveOut plug-in, should be more stable and more
    compatible (might have sacrificed a teeny bit of vis accuracy tho)
  * CDDB support now remembers if it hasn't worked recently to avoid
    from keeping popping up.
  * Fixed a dsp plug-in bug in Nitrane
  * Added SHOUTcast title reading to Nitrane, improved Nitrane's HTTP
    streaming (non-blocking connect, baby)
  * Added better MPEG 2.5 support to Nitrane (still don't have the right
    reordering tables, though, but an improvement nonetheless)
 
What's new in Winamp 2.05?
  * Fixed some vis->plug-in interface bugs
  * Fixed apply button in setup tab of prefs
  * Rewrote some memory chunk allocation code.
  * Added a buttload of IPC stuff (lots, baby!)
  * wVis 4.0: New effects, higher quality rendering, and DirectDraw fullscreen
    modes.
  * Fixed a skin bug
  * Fixed a few error-detection related bugs in Nitrane.
  * Preliminary CDDB Support (CDDBP only, no HTTP)
  * Much improved HTTP streaming. You can now psuedo-stream MOD,WAV,and MIDI
    files.
  * Improved MOD decoder (Thanks Jake!)
  * Updated icons. Fixed a lot of little cosmetic bugs.

What's new in Winamp 2.04?
  * Bugfixes. I had these logged but I lost the log file :(
  * Better installer integration (/install and /uninstall switch)
  * New, nicer, self checking installer. Uninstall too!
  * Fixed vis starting before first track bug
  * Added /CLASS="Winamp v1.y" switch
  * Added .ZIP support for skins. Simply drop a zipped skin in your Winamp\Skins
    directory!
  * Nitrane 1.24 with better sound quality and corrupt MP3 handling,
    two different EQ modes, and an experimental Aural Stimulation Mode.
  * Better "browse for directory" boxes.
  * More IPC stuff (EQ, Skins, etc -- see frontend.txt)
  

What's new in Winamp 2.03?
  * Improved shift selection in playlist editor
  * Better litestep support (litestep options in preferences/options, too)
  * Fixed a number of midi/cdda related bugs
  * Added WM_GETMINMAXINFO handler, to improve maximize handling and windowshade
  * Fixed some stupid (but very annoying) window region related bugs. 
  * Nitrane 1.22, for better sounding MP3 playback
  * New 'No Playlist Advance' option for DJs and people who like to jump
    around in playlists.
  * Snapping is now adjustable.
  
What's new in Winamp 2.02?
  * massive improvements to audio output system. No more skips!
    (be sure you set your audio output prefs to the recommended
     settings :)
  * Some dsp plug-in related enhancements.
  * fixed eq preset reloading bug
  * Optimized Nitrane's 3DNow! mode some more. About 10% faster.
    (went from 11.5% to 10.2% or so)
  * Ported some code to C in in_mod, for the upcoming 2.02 AXP build :)
 
What's new in Winamp 2.01?
  * made playlist editor use windows font.. resizable and skinnable
  * fixed a silly little hide-mainwindow-while-minimized-bug
  * added up/down arrow (and mousewheel scroll) to plwindowshade
  * fixed silly position bar moving bug
  * made EQ's 0-lock more accurate
  * made title-scroll option 
  * added width&height chex for pl
  * fixed error with sorting in skin selection box
  * fixed evil playlist editor 256 color bugs and alignment stuff
  * Nitrane 1.20. Faster, fully functional layer 2 support. Optimizations. 
    Better sounding half and quarter rate modes. fixed decoder mode setting
  * more... ! :)

What's new in Winamp 2.0?
  * I wouldn't know where to start =) sorry, just play with it..

----------- Old 1.x What's New ---------------------------------------------
What's new in Winamp 1.92 SP?
  * New Nitrane 1.0 MPEG audio decoder (mostly bugfixes)
  * New MOD/XM/IT player (see readme.txt)
  * New CDDA plug-in.
  * Fixed WAV plug-in
  * A few new plug-ins.

What's new in Winamp 1.92?
  * Mousewheel support (controls volume, or seeks when pressed)
  * Saves prefs even if you shut down while winamp is running
  * Skins can now change the color of most of Winamp's dialogs
    (see dialogs.txt in Skins\DColor)
  * Shift-minimize minimizes to tray
  * Plug-in name caching
  * Modeless prefs box, skin selector, about box
  * Better filetype registration. With unregistration, and individual 
    extension selection
  * Win98/IE4 taskbar support
  * added /config=file.ini (path optional) switch.
  * fixed some region related bugs
  * Apply works as expected in prefs now! :)
  * Nitrane MP3: totally new decoding engine with support for MMX, 3DNow!
    and more.
  * Removed MIDI/CDDA plug-ins temporarily (coming back soon when we get 
    them working better)

What's new in Winamp 1.91 sp1?
  * midi plugin: Fixed MIDI playback for files with spaces in their names
  * midi plugin: Trying to reinitialize synth on playback
  * wave plugin: fixed ACM problems on some systems with normal PCM files
    (bypass ACM)

What's new in Winamp 1.91?
  * better short-fn to lfn conversion
  * added new remove options to playlist editor
  * added /new switch, opens up a new winamp, always
  * none option for taskbar/tray display setting
  * Optimized prefs/plugins -- dsp plugins now must be named dsp_*.dll.
  * Made playlist editor keep track of playlist file (again)
  * Added SkinDir= and PluginDir= options for winamp.ini (add them manually 
    in [Winamp] in Winamp.ini to change)
  * Fixed up some delete playlist-then-hit-stop bugs
  * Fixed input-change bug in vis plugins
  * added skin enhancement: region.txt region specifier
  * added skin enhancement: balance.bmp is like volume.bmp but for 
    balance/panning bar
  * added skin enhancement: nums_ex.bmp allows for - sign definition :)
  * added 'playlist types' to open dialog
  * made snap to viewport snap on move in stead of on drop
  * added plug-in config hotkey/menu item
  * made vis_fs.dll default visualization
  * changed file type to 'winamp media file' from 'mpeg file'..
  * added demo.mp3, and auto-play on first run
  * fixed 2 digit bitrate/mixrate bug
  * fixed IPC_JUMPTOTIME bug (works now)
  * improved http m3u reading (error detection, yay)
  * made doublesize mode not so screwupy in win95
  * optimized title/length reading code
  * auto-idle when not playing
  * revised plug-in spec
  * added 'default extension' option
  * mp3 decoder: new time calculation code (all integer)
  * mp3 decoder: added options for different extensions 
    (and additional extensions)
  * mp3 decoder: added MMS streaming option
  * mp3 decoder: optimized size-changing checking code (for indirect streaming)
  * mp3 decoder: mixed-bitrate mp3s now display average bitrate
  * mp3 decoder: more genres
  * mp3 decoder: high genre bug fixed
  * mp3 decoder: improved http and mms streaming (with error detection n stuff)
  * mp3 decoder: fixed priority setting bug
  * mp3 decoder: added error messages for id3 editor box
  * mp3 decoder: new output system (optimized)
  * mod decoder: fixed priority setting bug
  * mod decoder: added better 8 bit support
  * mod decoder: new 'if title is empty' logic.. 
  * mod decoder: added support  for windowshade vu
  * mod decoder: added .669 support
  * mod decoder: new output system (optimized)
  * mod decoder: added waveform dsp plugin support
  * wav decoder: .VOC support. Only mono, 8 bit files are supported.
  * wav decoder: .VOC support supports silence blocks and changing samplerates
                 (all upsampled to 44.1kHz)
  * wav decoder: .WAV support. Uses ACM so you can play any .WAV file.
  * linein/cdda decoder: support for linein:// and .CDA cd tracks.


What's new in Winamp 1.90?
  * Major release - Winamp is now a general purpose audio player 
    (.MODs are back baby!)
  * Plug-in input sources. Included MP2/MP3 plug-in, MOD/XM/S3M/IT plug-in. 
    Coming soon: WAV/VOC/AU/AIFF, AAC, CD Audio, etc
  * Lots of bugfixes
  * New bugs (since we changed a *lot*)
  * Included new beta nifty fullscreen visualization library (with a dot
    fountain! :)

What's new in Winamp 1.82?
  * Even more ID3 genres
  * Decoder bug fixed (for corrupted mp3s)
  * Better shell integration (both play and queue options)

What's new in Winamp 1.81?
  * More ID3 genres
  * Fixed dsp plug-in non-working thingy
  * New 'alternate volume setting code' that works on all systems
  * You can now set the buffering time to 0 seconds for low-latency
  * No more integer mode (sucky)
  * New quarter-sample-rate mode
  * New 'agressive buffering' option
  * Cosmetic improvements
  * Winamp now remembers position in last playlist when starting
  * Random skin option box (see skin selector)

What's new in Winamp 1.80?
  * Skin support 
  * Plug-Ins now go in Plugins\ (move your old ones there)
  * Experimental integer mode for 486s
  * 64 bit mode for extra good sound
  * Removed Extra-HQ switch (always HQ now) 
  * Removed bufferless playback mode (slower according to vtune, just set 
    buffer-size to around 0.3 seconds for faster EQ, etc) 
  * Playlist editor bugfixes and enhancements
  * Many small bugfixes 
  * Optimized audio output code
  * Hold down shift while seeking for some fun 

What's new in Winamp 1.73?
  * .WAV writing bug fixed (sorry! :)

What's new in Winamp 1.72?
  * Winamp style dialogs are now an option
  * Improved streaming, supports nearly all web servers (we hope), and HTTP
    proxies.
  * Fixed many little bugs, little improvements

What's new in Winamp 1.70?
  * Redesigned playlist editor. Much more intuitive.
  * Fixed a TON of 256 color issues (vis looks better, dialogs look better)

What's new in Winamp 1.69?
  * Restyled playlist editor, graphical equalizer jump box, etc
    - they look MUCH nicer
  * 10 band graphical equalizer
    (Makes your 1.666 and earlier presets incompatible.. sorry)
  * Clutterbar now shows you the function of each button in the title
    field (when the mouse is over them)
  * Playlist editor's time calculation is better (uses ?'s if uncertain, and
    shows hours/minutes/seconds if applicable)
  * Playlist editor displays time for each track (if available)
  * More optimization, mostly in lower quality mode.
  * Plug-in related stability improvements (tries to tame badly behaved
    plug-ins)
  * Minor bugs fixed, including DSP selection, reverse stereo analyzer plug-in
  * Fixed focus-main-winamp-window-on-open-of-eq-or-pe bug. (phew)
  * Reverted the previous button back to the old way, of previous song, always
    (I like it better this way too)
  * New prebuffer after seek option
  * HQ button is now single-click
  * Sorry, this version changes the configuration format. You will need
    to reconfigure Winamp to your liking if you are upgrading.
  * A few new IPC calls

What's new in Winamp 1.666?
  * The Clutterbar.
  * Windowshade button 
  * Seek-in-windowshade mode 
  * Added desktop icon adding to preferences
  * Added a nifty hq control on main interface. 
  * New ID3 tags 
  * General purpose plug-in architecture (woohoo)
  * Fixed mixed-mode layer 2 bug (yay) 
  * Fixed "blip" bug in low quality imdct 
  * Optimized huffman decoding and requantinization
  * New high quality mode. Slower (but still quick), and sounds GREAT
  * Vastly improved shell integration. Try selecting lots of files in explorer,
    and hit "open" (doesn't work perfectly unless Winamp is already running)
  * Improved graphical equalizer (new ranges, more accurate, etc) 
  * Added live web links. 
  * Changed format of seeking display status 
  * Added nifty "add to playlist from explorer" (more or less) option to 
    prefs/initial setup 
  * Better VU meter with peak detection in windowshade 
  * More stable threading
  * Improved command line handling (supports relative pathnames better) 
  * Alternate volume setting mode (for some soundcards)
  * More ID3 format strings 
  * New buffer-all logic 
  * More IPC functions for programmers
  * %6 ID3 bug fixed (invalid genres) 

What's new in Winamp 1.64?
  * MAJOR "bug" fix: fixed buffer size logistics (enables 48/24/12khz output
    on many soundcards that wouldn't work before).

What's new in Winamp 1.62?
  * Numerous bugs fixed
  * Tooltip on titlebar
  * More menu items

What's new in Winamp 1.61?
  * Improved ID3 tag reading logic
  * Resizable playlist editor
  * Bugs fixed in .WAV writer (now replaces /\|,. etc with _)
  * Plug-in configuration hwndParent bug fixed 
  * Configurable icon in system tray
  * Yes, we like refinements


What's new in Winamp 1.60?
  * Improved sound quality (added HQ option)
  * Improved batch .WAV writer
  * Cleaned up playlist editor
  * New ID3->Title translation
  * New multiple instances logic
  * Lots of cosmetic improvements and refinements
  * Countless other improvements and bugfixes


What's new in Winamp 1.6 BETA?
  * Plugin Architecture
    * Visualization Plugins 
      * Simple test plugins (Analyser, Oscilliscope, VU meter) 
      * Fullscreen plugins (Analyser, Oscilliscope, Voiceprint, etc) 
        - requires DirectX3+ or NT4SP3 
      * Zygron's plugin library (some nifty effects)
      * Trippy Visualization plugin (rotozooms/motionblurrs an image with the 
        music) - requires DirectX3+ or NT4SP3 
      * 3D Spectrum Analyser plugin (Jeff's) - requires DirectX5. 
    * DSP Plugins 
      * Simple Reverb/Echo 
      * Simple Voice Removal (not extremely advanced) 
      * Note: these plugins might not be that great, but it's open for other 
        people to write plugins (and us when we get more time), so it will 
        be pretty useful. 
  * Right-click context menus in main interface 
  * Improved ID3 tag editor w/ MPEG info display 
  * VU meter and eject button in windowshade mode 
  * Increased visualization accuracy 
  * Faster seeking 
  * More reliable HTTP streaming 
  * Limited support for Microsoft NetShow audio streams (mms://) 
  * Bugfixes, new options (of course)


What's new in Winamp since 1.45?
  * MPEG 2.5 support (preliminary - occasional blips)
  * HTTP streaming support
  * New "Eject" button
  * Fixed clipping problem
  * New mini features
  * TONS of bugfixes

What's new in Winamp since 1.40?
  * Keyboard shortcuts for playlist editor (as requested)
    * Ctrl+A: selects all
	* Ctrl+N: selects none
	* Ctrl+I: inverts selection
	* Ctrl+L: loads playlist
	* Ctrl+S: saves playlist
	* Ctrl+O: sorts by title
	* Shift+O: sorts by filename
	* Ctrl+Shift+O: sorts by full filename (with path)
	* Ctrl+R: randomize
	* Ctrl+Shift+R: reverse
	* Delete: deletes selected mp3s.
	* Enter: plays (first) selecteed mp3
    * Insert: inserts mp3s
	* Shift+Insert: inserts directory
	* Control+Insert: inserts playlists
  * Super low latency low overhead buffering for some computers 
    * This lets my P5-133 use around 2% with ALL options on in Windows NT 
	  (but only with my GUS pnp, it doesn't help my AWE32. huh)
	* It isn't as skip-proof as normal buffering, so you will probably have
	  to give it some big priority boost in the preferences. But the performance
	  on some systems is amazing, the fastest I have EVER seen. 
  * Winamp is now 100% uncrippled nag-free Shareware that never expires. 
    * Registration for personal use is only $10.

What's new in Winamp since 1.20?
Here's a few:
  * Restyled playlist editor (with improved functionality)
    * Total time display in playlist editor
  * Rewritten playlisting engine (less buggy, more efficient)
  * Improved ID3 tag editor (alphabetical genres)
  * Revised main user interface
        * Display of positioning/volume/balance in songname field
	* Panning control
	* EQ & Playlist buttons
	* Enlarged songname field.
	* Manual songname scrolling returned
  * Doublesize mode
  * Optimized Visualization (less slowdown in win95)
  * Fire Analyzer Mode
  * Snap-to-viewport in always on top mode
  * Returned mixed-bitrate MPEG 2 stream support
  * Logarithmic EQ
	* Now has full -12db to +12db adjustment
	* Presets and auto-loading of settings (per mp3)
  * Higher priority by default
  * Changes to taskbar/system tray preferences take place immediately
  * .WAV ouput support (look in Preferences/Output/Device)
  * Added support for mixed bitrate streams
  * More file icons
  * Lots of bugfixes and refinements