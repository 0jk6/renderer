work in progress 3d software renderer based on SDL. (Only supports wireframe view for now)

### Building

On Linux, install `libsdl2` and then run the folowing command
`g++ -c ./*.cpp -g -Wall && g++ *.o -o ./main -L -lSDL2main -lSDL2`

On Window, you can move the `SDL2` files into `C:/MinGW/lib` and run the `build.bat` file.

Once you did that, you can run `./main Monkey.txt` to view the Monkey in wireframe view.


### Here's a screenshot of Monkey
![img file](https://github.com/threadException/renderer/blob/main/screenshot.png)

### Credits
https://github.com/ssloy/tinyrenderer