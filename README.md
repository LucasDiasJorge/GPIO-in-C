# GPIO in C
 
sudo apt-get update

sudo apt-get install git build-essential -y

git clone https://github.com/zhaolei/WiringOP.git -b h3

cd WiringOP

sudo chmod +x ./build

sudo ./build

gcc main.c -o main -lwiringPi -pthread
