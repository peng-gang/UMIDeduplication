//
//  main.cpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/29/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "UMIGroup.hpp"
#include "UMISingleGroup.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    string file1 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R1_001.fastq.gz";
    string file2 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R2_001.fastq.gz";
    ofstream fout1;
    ofstream fout2;
    
    UMIGroup ug(file1, file2, true);
    vector<string> umi12({"TTTCACCATAAAAAAAAA", "GTTTCACCAAAAAAAAAA", "GGTTTCACCAAAAAAAAA", "TTTTCACCAAAAAAAAAA", "GGGTTTCACAAAAAAAAA"});
    
    for(size_t i=0; i< umi12.size(); i++){
        UMI tmp = ug.getUMI(umi12[i]);
        vector<string> r1 = tmp.getReads1();
        fout1.open(("/Users/gpeng/Work/UMI/rlt/R12/" + umi12[i] + "_R1.txt").c_str());
        for(vector<string>::iterator it = r1.begin(); it!=r1.end(); it++){
            fout1<<*it<<endl;
        }
        fout1.close();
        
        vector<string> r2 = tmp.getReads2();
        fout2.open(("/Users/gpeng/Work/UMI/rlt/R12/" + umi12[i] + "_R2.txt").c_str());
        for(vector<string>::iterator it = r2.begin(); it!=r2.end(); it++){
            fout2<<*it<<endl;
        }
        fout2.close();
    }
    /*
    cout<<"R1+R2:"<<endl;
    cout << ug.getNumReads()<<endl;
    map<string, size_t> numUMIReads = ug.getNumUMIReads();
    cout<<numUMIReads.size()<<endl;
    
    std::ofstream ofs ("/Users/gpeng/Work/UMI/rlt/NumUMIReads.txt", std::ofstream::out);
    for(map<string, size_t>::iterator it = numUMIReads.begin(); it != numUMIReads.end(); it++){
        ofs << it->first << "\t" << it->second << endl;
    }
    ofs.close();
     */
    
     
    
    UMISingleGroup ug1(file1, true);
    vector<string> umi1({"TTTCACCAT" "GTTTCACCA" "GGGTGTCTG" "GGTTTCACC" "TTACGCCAC"});
    
    for(size_t i=0; i< umi1.size(); i++){
        UMISingle tmp = ug1.getUMI(umi1[i]);
        vector<string> r1 = tmp.getReads();
        fout1.open(("/Users/gpeng/Work/UMI/rlt/R1/" + umi1[i] + ".txt").c_str());
        for(vector<string>::iterator it = r1.begin(); it!=r1.end(); it++){
            fout1<<*it<<endl;
        }
        fout1.close();
    }
    
    /*
    cout<<"R1:"<<endl;
    cout << ug1.getNumReads()<<endl;
    map<string, size_t> numUMIReads1 = ug1.getNumUMIReads();
    cout<<numUMIReads1.size()<<endl;
    
    std::ofstream ofs1 ("/Users/gpeng/Work/UMI/rlt/NumUMIReads1.txt", std::ofstream::out);
    for(map<string, size_t>::iterator it = numUMIReads1.begin(); it != numUMIReads1.end(); it++){
        ofs1 << it->first << "\t" << it->second << endl;
    }
    ofs1.close();
     */
    
    
    
    
    UMISingleGroup ug2(file2, true);
    vector<string> umi2({"AAAAAAAAA" "TTGTCGCTT" "TGGGACTTG" "CTGCCTGGC" "TAAAAAAAA"});
    
    for(size_t i=0; i< umi2.size(); i++){
        UMISingle tmp = ug2.getUMI(umi2[i]);
        vector<string> r2 = tmp.getReads();
        fout2.open(("/Users/gpeng/Work/UMI/rlt/R2/" + umi2[i] + ".txt").c_str());
        for(vector<string>::iterator it = r2.begin(); it!=r2.end(); it++){
            fout2<<*it<<endl;
        }
        fout2.close();
    }
    
    /*
    cout<<"R2:"<<endl;
    cout << ug2.getNumReads()<<endl;
    map<string, size_t> numUMIReads2 = ug2.getNumUMIReads();
    cout<<numUMIReads2.size()<<endl;
    
    std::ofstream ofs2 ("/Users/gpeng/Work/UMI/rlt/NumUMIReads2.txt", std::ofstream::out);
    for(map<string, size_t>::iterator it = numUMIReads2.begin(); it != numUMIReads2.end(); it++){
        ofs2 << it->first << "\t" << it->second << endl;
    }
    ofs2.close();
     */
    
    return 0;
}
