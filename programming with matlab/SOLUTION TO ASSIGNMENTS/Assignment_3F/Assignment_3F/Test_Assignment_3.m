clear
load students student % load structure array student from file students.mat
% students.mat must be in the same directory as the script
result=find_match('016',student)
% correct answer: 16    21    24    28    32
result=find_match(016,student)
% correct answer: error message and empty result
result=find_match('Moha',student)
% correct answer: 2     6
result=find_match('moha',student)
% correct answer: 2     6
result=find_match('0663',student)
% correct answer: 2     4     7    19    20    22    23    25    29
result=find_match('0663',student,'scode')
% correct answer: 2     4     7    19    20    22    23    25    29
result=find_match('0663',student,'Scode')
% correct answer: warning message and empty result
result=find_match('sal',student,'name')
% correct answer: 25    26
result=find_match('016',student,'matnum')
% correct answer: 16    21    24    28    32
result=find_match('w',student,'gender')
% correct answer: 1     7    21    24    32
result=find_match('a',student,'gender')
% correct answer: empty result
result=find_match('y',student)
% correct answer: 6    19    20    27    31





