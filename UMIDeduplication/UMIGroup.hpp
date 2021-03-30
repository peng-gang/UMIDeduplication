//
//  UMIGroup.hpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/29/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#ifndef UMIGroup_hpp
#define UMIGroup_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include "UMI.hpp"

class UMIGroup{
private:
    std::map<std::string, UMI> umis;
    std::size_t numReads;
    
public:
    UMIGroup();
    UMIGroup(std::string f1, std::string f2, bool gzFile = true);
    bool insert(UMI umi);
    
    std::size_t getNumReads() {return numReads;}
    std::size_t getNumUMI() {return umis.size();}
    
    std::vector<std::size_t> getNumUMIReads();
};

#endif /* UMIGroup_hpp */
