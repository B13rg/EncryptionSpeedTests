.DEFAULT_GOAL := all

all: Hash Block AES Public Elliptical Depreciated

RSA:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./RSA/main.cpp -lcryptopp -I ./cryptopp

Elliptical:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Elliptical.sh ./Elliptical\ Curve/main.cpp -lcryptopp -I ./cryptopp

Depreciated:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./Depreciated/main.cpp -lcryptopp -I ./cryptopp

Public:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./Public\ Key/main.cpp -lcryptopp -I ./cryptopp

AES:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./AES/main.cpp -lcryptopp -I ./cryptopp

Block:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./Block\ Ciphers/main.cpp -lcryptopp -I ./cryptopp

Hash:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./Hash\ Functions/main.cpp -lcryptopp -I ./cryptopp

clean:
	-rm *.sh
