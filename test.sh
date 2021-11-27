FLAGS="-g -Wall -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"

rm *.o
rm memtest_textbro

cc -c src/draw.c $FLAGS
cc -c src/files.c $FLAGS
cc -c src/tests/tests.c $FLAGS
cc draw.o files.o tests.o -o memtest_textbro $FLAGS
