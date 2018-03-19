//
// Created by Maciej Syska on 18/03/2018.
//

#include "TinyUrl.h"

        using std::string;
        using std::unique_ptr;
        using std::make_unique;

        namespace tinyurl
        {
            std::array<char,6> Hash={'0','0','0','0','0','0'};

            unique_ptr<TinyUrlCodec> Init() {
                unique_ptr<TinyUrlCodec> uniqueTinyUrlPtr = make_unique<TinyUrlCodec>();
                return uniqueTinyUrlPtr;
            }

            void NextHash(std::array<char, 6> *state) {
                /*
                  char zk;
                for (int k = 5; k >= 0; k--) {
                    zk = (*state)[k];
                    if (zk != 'z') {
                        int offset = 1;
                        if (zk == '9')
                            offset = 8;
                        else if (zk == 'Z')
                            offset = 7;
                        (*state)[k] += offset;
                        break;
                    }
                    else
                        (*state)[k] = '0';
                 */
                bool zwieksznast=false;
                for(int i=5;i>=0;i--){

                    char znak=(*state)[i];
                    if(i==5 or zwieksznast==true){
                        znak=znak+1;
                        zwieksznast=false;
                    }
                    if(znak==58){
                        znak=65;
                    }
                    else if(znak==91){
                        znak=97;
                    }
                    else if(znak==123){
                        znak=48;
                        zwieksznast=true;
                    }
                    (*state)[i]=znak;

                }}
            }
