.DEFAULT_GOAL := all

all: Hash Block AES Public Elliptical Depreciated

RSA:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o RSA.sh ./RSA/main.cpp -lcryptopp -I ./cryptopp

Elliptical:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Elliptical.sh ./Elliptical\ Curve/elliptical.cpp -lcryptopp -I ./cryptopp

Depreciated:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Depreciated.sh ./Depreciated/depreciated.cpp -lcryptopp -I ./cryptopp

Public:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Public_Key.sh ./Public\ Key/public_key.cpp -lcryptopp -I ./cryptopp

AES:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o AES.sh ./AES/aes.cpp -lcryptopp -I ./cryptopp

Block:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Block_Hash.sh ./Block\ Ciphers/block.cpp -lcryptopp -I ./cryptopp

Hash:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o Hash.sh ./Hash\ Functions/hash.cpp -lcryptopp -I ./cryptopp

clean:
	-rm *.sh
