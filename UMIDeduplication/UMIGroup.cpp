//
//  UMIGroup.cpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/29/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#include "UMIGroup.hpp"
#include <iostream>
#include <fstream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>

using namespace std;

UMIGroup::UMIGroup(){
    numReads = 0;
    umis.clear();
}

UMIGroup::UMIGroup(std::string f1, std::string f2, bool gzFile){
    numReads = 0;
    umis.clear();
    if(gzFile){
        ifstream file1(f1.c_str(), ios_base::in | ios_base::binary);
        ifstream file2(f2.c_str(), ios_base::in | ios_base::binary);
        try {
            boost::iostreams::filtering_istream fin1;
            fin1.push(boost::iostreams::gzip_decompressor());
            fin1.push(file1);
            
            boost::iostreams::filtering_istream fin2;
            fin2.push(boost::iostreams::gzip_decompressor());
            fin2.push(file2);
            
            while(true){
                std::string identifier1, identifier2;
                if(!(std::getline(fin1, identifier1) && std::getline(fin2, identifier2))){
                    break;
                }
                
                /*
                if(identifier1 != identifier2){
                    break;
                }
                 */
                
                std::string read1, read2;
                if(!(std::getline(fin1, read1) && std::getline(fin2, read2))){
                    break;
                }
                
                std::string opt1, opt2;
                if(!(std::getline(fin1, opt1) && std::getline(fin2, opt2))){
                    break;
                }
                
                std::string qs1, qs2;
                if(!(std::getline(fin1, qs1) && std::getline(fin2, qs2))){
                    break;
                }
                
                string umi = read1.substr(0, 9) + read2.substr(0, 9);
                map<string, UMI>::iterator it = umis.find(umi);
                if(it != umis.end()){
                    //cout<<umi<<endl;
                    it->second.insert(read1, read2, qs1, qs2, "", "");
                } else {
                    UMI umiObj(umi, read1, read2, qs1, qs2, "", "");
                    umis.insert(pair<string, UMI> (umi, umiObj));
                }
                
                numReads++;
                
                /*
                if(numReads > 1000){
                    break;
                }
                 */
            }
        }
        catch(const boost::iostreams::gzip_error& e) {
             std::cout << e.what() << '\n';
        }
        file1.close();
        file2.close();
    } else {
        umis.clear();
    }
}

bool UMIGroup::insert(UMI umi){
    map<string, UMI>::iterator it = umis.find(umi.getUMI());
    if(it != umis.end()){
        it->second.getReads1().insert(it->second.getReads1().end(), umi.getReads1().begin(), umi.getReads1().end());
        it->second.getReads2().insert(it->second.getReads2().end(), umi.getReads2().begin(), umi.getReads2().end());
        
        it->second.getQss1().insert(it->second.getQss1().end(), umi.getQss1().begin(), umi.getQss1().end());
        it->second.getQss2().insert(it->second.getQss2().end(), umi.getQss2().begin(), umi.getQss2().end());
        
        it->second.getPrimers1().insert(it->second.getPrimers1().end(), umi.getPrimers1().begin(), umi.getPrimers1().end());
        it->second.getPrimers2().insert(it->second.getPrimers2().end(), umi.getPrimers2().begin(), umi.getPrimers2().end());
        
    } else {
        umis.insert(pair<string, UMI> (umi.getUMI(), umi));
    }
    return true;
}

vector<size_t> UMIGroup::getNumUMIReads(){
    vector<size_t> rlt;
    
    for(map<string, UMI>::iterator it = umis.begin(); it != umis.end(); it++){
        rlt.push_back(it->second.getNumReads());
    }
    
    return rlt;
}
