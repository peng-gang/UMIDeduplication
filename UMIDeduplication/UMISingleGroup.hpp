//
//  UMISingleGroup.hpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/30/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#ifndef UMISingleGroup_hpp
#define UMISingleGroup_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include "UMISingle.hpp"

class UMISingleGroup{
private:
    std::map<std::string, UMISingle> umis;
    std::size_t numReads;
    
public:
    UMISingleGroup();
    UMISingleGroup(std::string inputFile, bool gzFile = true);
    bool insert(UMISingle umi);
    
    std::size_t getNumReads() {return numReads;}
    std::size_t getNumUMI() {return umis.size();}
    
    UMISingle getUMI(std::string umi);
    
   std::map<std::string, std::size_t> getNumUMIReads();
};

#endif /* UMISingleGroup_hpp */
