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
#include "UMIGroup.hpp"
#include "UMISingleGroup.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
    string file1 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R1_001.fastq.gz";
    string file2 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R2_001.fastq.gz";
    
    UMIGroup ug(file1, file2, true);
    
    cout << ug.getNumReads()<<endl;
    
    vector<unsigned> numUMIReads = ug.getNumUMIReads();
    
    cout<<numUMIReads.size()<<endl;
    
    std::ofstream ofs ("/Users/gpeng/Work/UMI/test.txt", std::ofstream::out);
    for(size_t i=0; i<numUMIReads.size(); i++){
        ofs << numUMIReads[i] << endl;
    }
    ofs.close();
     */
    
    string file1 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R1_001.fastq.gz";
    string file2 = "/Users/gpeng/Work/UMI/data/noTrim/S817_AGGCAGAA-TAGATCGC_L001_R2_001.fastq.gz";
    
    UMISingleGroup ug1(file1, true);
    
    cout<<"R1:"<<endl;
    cout << ug1.getNumReads()<<endl;
    vector<size_t> numUMIReads1 = ug1.getNumUMIReads();
    cout<<numUMIReads1.size()<<endl;
    
    std::ofstream ofs1 ("/Users/gpeng/Work/UMI/test1.txt", std::ofstream::out);
    for(size_t i=0; i<numUMIReads1.size(); i++){
        ofs1 << numUMIReads1[i] << endl;
    }
    ofs1.close();
    
    UMISingleGroup ug2(file2, true);
    
    cout<<"R2:"<<endl;
    cout << ug2.getNumReads()<<endl;
    vector<size_t> numUMIReads2 = ug2.getNumUMIReads();
    cout<<numUMIReads2.size()<<endl;
    
    std::ofstream ofs2 ("/Users/gpeng/Work/UMI/test2.txt", std::ofstream::out);
    for(size_t i=0; i<numUMIReads2.size(); i++){
        ofs2 << numUMIReads2[i] << endl;
    }
    ofs2.close();
    
    return 0;
}
