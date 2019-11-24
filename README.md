# College_Management_System
CMS Application using CPP

College Management System (CMS)

Object-Oriented Programming with C++

By : Surya Ammisetti

Resource (Book): Object-Oriented Programming with C++ by E Balagurusamy (7e)

IDE Used : Code Blocks 17.12

Learning Objectives
After going through project, you will be able to 
	Develop menu-driven applications in C++
	Apply authentication in menu-driven projects
	Apply the file-handling concepts

COLLEGE MANAGEMENT SYSTEM (CMS) : 
CMS is a command-driven application that helps to maintain student and faculty records. It makes use of unique IDs and password 
to restrict the access and usage of different areas of the portal to its correct target audience. The faculty portal allows the 
faculty user to update faculty profile, including allocation of subjects to be taught. Likewise, the student portal helps to 
maintain student profile information, including allocation and de-allocation of subjects to the students. The admin portal is 
used for administrative purpose. It helps to make the user entry for the first time.
The CMS  application code makes use of a wide array of C++ programming features. These includes :
•	Concept of inheritance for code reusability
•	Concept of function overloading that enhances the code readability
•	Handling of simple exceptions
•	Application of file-handling concepts for performing operations, such as read, write, append, check for various I/O errors, etc
•	Use of various I/O manipulators to display the output in a formatted manner.

Element	Description : 
Admin         : It is used to maintain the faculty and student profiles. It provides a unique login to both profile users, and 
              allows them to update their records further.
login()       : It authenticates the login of both profile users(students and faculties).
recover()     : It helps both profile users to recover the password.
getsdata()    : It is used to make the student data entry from the ADMIN portal.
stprofile()   : It allows authorized student to display their profile details.
knowstsub()   : It allows authorized student to get their subjects list.
addstsub()    : It allows the student to add a new subject in profile.
delstsub()    : It allows the student to delete a subject from profile.
modstprofile(): It allows the student to modify the personal profile details.
getfadata()   : It allows the Admin to make a new entry of the faculty user.
faprofile()   : It allows authorized faculty to display their profile details.
knowfasub()   : It allows authorized faculty to get thier subjects list.
addfsub()     : It allows the faculty to add a new subject in profile.
delfasub()    : It allows the faculty to delete a subjects from profile.
modfaprofile(): It allows the faculty to modify the personal profile details.
stdisplay()   : It displays all the students records to the admin.
fadisplay()	  : It displays all the faculty records to the admin.

Overall Logics used by CMS Application :
1. The Welcome Page of the CMS application is displayed at first. On hitting the Enter Key, the user enters the main Login Page. The 
   user can login as Admin, Student or Faculty.
    •	The Admin Panel is used to create and maintain the databases of all the faculty and student users.
    •	The Faculty Panel enables access to all the registered faculties in the database.
    •	The Student Panel enables access to all the registered students in the database.
2. Next, the user is distinguished as Admin, Student or Faculty based on the choice selected by the user. Subsequently, the user is 
   redirected to the respective Login page.
3. Each of the respective portals are menu-driven. It shown a menu of operations that the users (faculty, student, admin) can perform. 
