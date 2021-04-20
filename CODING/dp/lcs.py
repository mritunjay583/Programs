

def lcs(string1,string2):
    if len(string1)==0 or len(string2)==0:
        return 0
    
    if string1[-1]==string2[-1]:
        return 1+lcs(string1[:-1],string2[:-1])
    else:
        return max(lcs(string1[:-1],string2),lcs(string1,string2[:-1]))



s1="SPRINGTIME"
s2="PIONEER"

print(lcs(s1,s2))
# print(dplcs(s1,s2))
