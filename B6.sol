
// SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract StudentData{


    struct Student{

        uint roll;
        string name;
        uint mark;
    }

    Student[] public students;

    event LogMessage(string message);
   
   fallback() external payable{
    // 
   }

   receive() external  payable {
    // 
    emit LogMessage("Fallback Funtion is called ");
   }

   function addStudent(uint _roll,string memory _name, uint _marks) public{
     Student memory newStudent=  Student(_roll,_name,_marks);
     students.push(newStudent);

   }

   function getStudentLength() public view returns(uint){
    return students.length;
   }

  function getStudents() public view returns (uint[] memory, string[] memory,uint[] memory){
    uint length=students.length;

    uint[]memory rolls=new uint[](length);
     string[]memory names=new string[](length);
      uint[]memory marks=new uint[](length);
  

     for(uint i=0;i<length;i++){
        rolls[i]=students[i].roll;
        names[i]=students[i].name;
        marks[i]=students[i].mark;

     }


return (rolls,names,marks);
  }



}
