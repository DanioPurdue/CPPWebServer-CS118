# CS118Project1
cs118Project1

## Allen's Notes:
@Danio, 

The only issue now is that there is a content length mismatch for .gif files, everything else works.

How to run the code:
Start in main project directory and start docker desktop:
```
./start.sh -p 5000
cd build
make
./server
```

## Danio's Notes:
@Allen,

The server can support 404 not found page only. I also added a makefile. I used the request object added by you. I did not use the response object, because we just need to server few static page and it might be an overkill to use the custom reply object.
## Team Members
* Allen Nikka, UID: 405027870
* Jianxiong Wang, UID: 005229714


## TODOs

1. should we add an index page?
2. shoulde we use c++14?

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
