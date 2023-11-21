// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.7.0 <0.9.0;

contract EmployeeManagementSystem
{
    struct EmployeeStruct 
    {
        uint ID;
        string fName;
        string lName;
        uint salary;
    }
    address public owner;
    uint public empCount = 0;
    EmployeeStruct[] public empRecords;

    // Event for logging messages
    event LogMessage(string message);
    
    constructor() 
    {
        owner = msg.sender;
    }

    function addNewRecords(uint _ID, string memory _fName, string memory _lName, uint _salary) public payable 
    {
        empCount = empCount + 1;
        empRecords.push(EmployeeStruct(_ID, _fName, _lName, _salary));
    }

    function getAllRecords() public view returns (EmployeeStruct[] memory) 
    {
        return empRecords;
    }

    // Fallback function
    receive() external payable 
    {
    // Print a message or perform any other action
        emit LogMessage("Fallback function called. Ether received.");
    }
}
