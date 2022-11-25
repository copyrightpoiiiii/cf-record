f = open("head.cpp",'r')
out = open("head.json",'w+')
lines=f.readlines()
for line in lines:
    print('"' + line.strip('\n').replace('"','\\"').replace("\t",'    ')+'",',file=out)