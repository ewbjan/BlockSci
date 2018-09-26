//
//  address_proxy_main.cpp
//  blocksci
//
//  Created by Harry Kalodner on 9/22/18.
//
//

#include "address_proxy_py.hpp"
#include "proxy_py.hpp"
#include "proxy/basic.hpp"

#include <blocksci/cluster/cluster.hpp>
#include <blocksci/chain/block.hpp>

void addAddressProxyMethodsMain(AllProxyClasses<blocksci::AnyScript> &cls) {
	cls.setupBasicProxy(AddProxyMethods{});
}
