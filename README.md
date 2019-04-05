# CS118Project1
cs118Project1

## Allen's Notes:
@Danio, you can check unbuntu version in container with this command:  cat /etc/lsb-release
You can build the container with ./start.sh, and pass a port to map to host machine like this: ./start.sh -p 8080 
This will bind port 8080 from the local machine to the port 8080 on the docker. Also if the bash script doesn't work, check the line endings, 
they might have gotten corrupted to the windows style CRLF rather than LF.

## Team Members
* Allen Nikka, UID: 405027870

## Submission Requirements:
•Your source codes (e.g.webserver.c).  The code of the server can be more than one file.
•A Makefile.  The TAs will only type make to compile your code.
•Your report in PDF format only (report.pdf).
•A README file which will contain student names and student IDs.Your report should not exceed 6 pages.  

In your report:
1.  Give a high-level description of your server’s design.
2.  What difficulties did you face and how did you solve them?
3.  Include  a  brief  manual  in  the  report  to  explain  how  to  compile  and  run  your  source  code(if  TAs  cannot  compile  and  run  your  source  code  by  reading  your  manual,  the  project  is considered not to be finished).
4.  Include  and  briefly  explain  some  sample  outputs  of  your  client-server  (e.g.   in  Part  A  you should be able to see an HTTP request).  You do not have to write a lot of details about the code, but just adequately comment your source code.  The cover page of the report should include the name of the course and project, your partner’s name, and student ID.3