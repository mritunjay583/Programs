import re

s="to their mom"

pattern=[re.compile(r"to the$"),re.compile(r"^to the$"),re.compile(r" to the ")]
res=0
for i in pattern:
    print(re.findall(i,s));
    res+=len(re.findall(i,s));

if(res>0):
    print("yes")
else:
    print("no")