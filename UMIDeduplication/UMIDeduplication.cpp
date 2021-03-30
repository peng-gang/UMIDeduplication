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

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
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
    
    return 0;
}
