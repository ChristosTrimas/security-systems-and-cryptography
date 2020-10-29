#!/bin/bash

echo "Give your AM"
read am

./assign_1 -i encryptme_256.txt -o decryptme_256.txt -p TUC$am -b 256 -e
./assign_1 -i hpy414_decryptme_128.txt -o hpy414_encryptme_128.txt -p hpy414 -b 128 -d
./assign_1 -i signme_128.txt -o verifyme_128.txt -p TUC$am -b 128 -s
./assign_1 -i hpy414_verifyme_256.txt -o hpy414_signme_256.txt -p hpy414 -b 256 -v
./assign_1 -i hpy414_verifyme_128.txt -o hpy414_signme_128.txt -p hpy414 -b 128 -v


./assign_1 -i decryptme_256.txt -o encryptme_256_out.txt -p TUC$am -b 256 -d
./assign_1 -i hpy414_encryptme_128.txt -o hpy414_decryptme_128_out.txt -p hpy414 -b 128 -e
./assign_1 -i verifyme_128.txt -o signme_128_out.txt -p TUC$am -b 128 -v
./assign_1 -i hpy414_signme_256.txt -o hpy414_verifyme_256_out.txt -p hpy414 -b 256 -s
./assign_1 -i hpy414_signme_128.txt -o hpy414_verifyme_128_out.txt -p hpy414 -b 128 -s