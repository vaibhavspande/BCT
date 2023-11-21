// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.7.0 <0.9.0;

contract CustomerManagementSystem
{
    struct CustomerStruct 
    {
        uint ID;
        string fName;
        string lName;
        uint age;
    }
    address public owner;
    uint public custCount = 0;
    CustomerStruct[] public custRecords;

    // Event for logging messages
    event LogMessage(string message);
    
    constructor() 
    {
        owner = msg.sender;
    }

    function addNewRecords(uint _ID, string memory _fName, string memory _lName, uint _age) public payable 
    {
        custCount = custCount + 1;
        custRecords.push(CustomerStruct(_ID, _fName, _lName, _age));
    }

    function getAllRecords() public view returns (CustomerStruct[] memory) 
    {
        return custRecords;
    }

    // Fallback function
    receive() external payable 
    {
    // Print a message or perform any other action
        emit LogMessage("Fallback function called. Ether received.");
    }
}
