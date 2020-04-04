# gameLauncher
> Laucher for Ultimatum RTS
The server needs to have a http://files.ultirts.net/newrelease/version present for change detection, and automagically downloads it when it differs from the local. a helper program will also be downloaded when there is a version mismatch. http://files.ultirts.net/newrelease/updater it will set everything up, delete itself, and then launch the new self upon the return of the helper script.
use `g++ -o /path/launcher.exe launch.cpp` to compile
`chmod +Xx /path/*` to grant exe permission
`/path/launcher.exe` to run
