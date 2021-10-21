# coord_trans
Coordinate system conversion, seven-parameter conversion realized by C language

#### usage:

1.build

```shell
system$ make
cc -g -Wall -O0 -std=c99 -g   -c -o main.o main.c
cc -g -Wall -O0 -std=c99 -g   -c -o coordtrans.o coordtrans.c
gcc -g -Wall -O0 -std=c99 -g main.o coordtrans.o -o coordtrans -lm
system$ ./coordtrans
test1->
WGS84->WGS84(大地坐标转平面坐标)[原始坐标]:b:37.404744, l:118.105194, h:0.000000
WGS84->WGS84(大地坐标转平面坐标)[目的坐标]:x:4141435.293393, y:509313.673443, h:-0.000000
WGS84->WGS84(平面坐标转大地坐标)[原始坐标]:b:4141435.293393, l:509313.673443, h:-0.000000
WGS84->WGS84(平面坐标转大地坐标)[目的坐标]:x:37.404744, y:118.105194, h:-0.000000
test2->
WGS84->WGS84(大地坐标转平面坐标)[原始坐标]:b:37.500176, l:118.100050, h:0.000000
WGS84->WGS84(大地坐标转平面坐标)[目的坐标]:x:4152026.420370, y:508846.973730, h:-0.000000
WGS84->WGS84(平面坐标转大地坐标)[原始坐标]:b:4152026.420370, l:508846.973730, h:-0.000000
WGS84->WGS84(平面坐标转大地坐标)[目的坐标]:x:37.500176, y:118.100050, h:-0.000000
system$ make clean
rm -f *.o coordtrans
```

#### note:

Can be tested against "COORD.exe" program