// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.7.0 <0.9.0;

contract MarksManagmtSys 
{
    struct StudentStruct 
    {
        uint ID;
        string fName;
        string lName;
        uint marks;
    }
    address public owner;
    uint public stdCount = 0;
    StudentStruct[] public stdRecords;

    // Event for logging messages
    event LogMessage(string message);
    
    constructor() 
    {
        owner = msg.sender;
    }

    function addNewRecords(uint _ID, string memory _fName, string memory _lName, uint _marks) public payable 
    {
        stdCount = stdCount + 1;
        stdRecords.push(StudentStruct(_ID, _fName, _lName, _marks));
    }

    function getAllRecords() public view returns (StudentStruct[] memory) 
    {
        return stdRecords;
    }

    // Fallback function
    receive() external payable 
    {
    // Print a message or perform any other action
        emit LogMessage("Fallback function called. Ether received.");
    }
}
