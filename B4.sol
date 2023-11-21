// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.8.18;

contract ProductInventory {
    mapping(uint => uint) private products; // Product ID => Quantity mapping

    function receiveProduct(uint productId,  uint quantity) public {
        require(quantity > 0, "Quantity should be greater than 0");
        products[productId] += quantity;
    }

    function sellProduct(uint productId, uint quantity) public {
        require(products[productId] >= quantity, "Insufficient stock");
        require(quantity > 0, "Quantity should be greater than 0");
        products[productId] -= quantity;
    }

    function displayStock(uint productId) public view returns (uint) {
        return products[productId];
    }
}
