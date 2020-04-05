# gameLauncher
> Laucher for Ultimatum RTS

### The server needs to have a http://files.ultirts.net/newrelease/version present for change detection, and automagically downloads it when it differs from the local. a helper program will also be downloaded when there is a version mismatch. http://files.ultirts.net/newrelease/updater it will set everything up, delete itself, and then launch the new self upon the return of the helper script.
## To run: 
`/path/launcher.exe`

## To compile:
use `g++ -o launcher.exe launcher.cpp -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_test` to compile
`chmod +Xx /path/*` to grant exe permission
`/path/launcher.exe` to run
