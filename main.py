def read_raw_data():
    File=open("sample.txt","r")
    s=File.read()
    s=list(s)
    i=0
    while(i<len(s)):
        if((ord(s[i])>=ord('0') and ord(s[i])<=ord('9')) or s[i]=="'" or s[i]=="\n" or s[i]==' '):
            s.pop(i)
            continue
        if(s[i]=='?' or s[i]=='_'):
            s[i]='U'
        if(s[i]=='S' and s[i+1]=='t' and s[i+2]=='r'):
            s[i+1]='e'
            s[i+2]='q'
            i+=2
        i+=1
    s="".join(s)
    s=s.split("Seq{}=")
    s.pop(0)
    sequence=[]
    secondary_structure=[]
    for i in range(len(s)):
        if(i%2==0):
            sequence.append(s[i])
        else:
            secondary_structure.append(s[i])
    # print(sequence)
    # print(secondary_structure)
    return(sequence,secondary_structure)
def add_dummy_elements(w_len):
    sequence,ss=read_raw_data()
    pad_len=(w_len-1)//2
    print(pad_len)
    fSeq=sequence
    for i in range(len(fSeq)):
        fSeq[i]="X"*pad_len+fSeq[i]+"X"*pad_len
    # print(fSeq)
    return(fSeq)

def Data(w_len):
    fSeq=add_dummy_elements(w_len)
    seq,secondary_structure=read_raw_data()
    input_data=[]
    output_data=[]
    v=0
    for i in fSeq:
        for j in range(len(secondary_structure[v])):
            input_data.append(i[j:j+w_len])
            output_data.append(secondary_structure[v][j])
        v+=1
 
    ltd=int(len(input_data)*0.7)
    Tr_in=input_data[:ltd]
    Tr_out=output_data[:ltd]
    Test_in=input_data[ltd:]
    Test_out=output_data[ltd:]
    return([Tr_in,Tr_out,Test_in,Test_out])
w_len=7
Tr_and_Test_data=Data(w_len)

for i in range(len(Tr_and_Test_data[0])):
    if(i<len(Tr_and_Test_data[2])):
        print(Tr_and_Test_data[0][i],Tr_and_Test_data[1][i],Tr_and_Test_data[2][i],Tr_and_Test_data[3][i])
    else:
        print(Tr_and_Test_data[0][i],Tr_and_Test_data[1][i])



Tr_in = Tr_and_Test_data[0]
Tr_out = Tr_and_Test_data[1]
Test_in =Tr_and_Test_data[2]
Test_out =Tr_and_Test_data[3]


def class_sep(Tr_in,Tr_out):
    Sec_Struct_list=['G','H','I','B','E','T','S','U']
    Sec_Struct_dict={}
    for i in Sec_Struct_list:
        Sec_Struct_dict[i]=[]
    for i in range(len(Tr_out)):
        Sec_Struct_dict[Tr_out[i]].append(Tr_in[i])
    print(Sec_Struct_dict['I'])
    return Sec_Struct_dict,Sec_Struct_list

sec_struct_dict,sec_struct_list=class_sep(Tr_and_Test_data[0],Tr_and_Test_data[1])

def class_prob(Sec_Struct_dict,Sec_Struct_list):
    aa="ARNDCQEGHILKMFPSTWYVX"
    aa_count={}
    for i in Sec_Struct_list:
        aa_count[i]={}
        for j in aa:
            aa_count[i][j]=[0 for i in range(w_len)]
    class_p={}
    P_tables={}
    for i in Sec_Struct_list:
        P_tables[i]={}
        class_p[i]=len(Sec_Struct_dict[i])/len(Tr_in)
   
    for i in Sec_Struct_list:
        for j in aa:
            P_tables[i][j]=[0 for i in range(w_len)]
   
    for i in Sec_Struct_list:
        for j in Sec_Struct_dict[i]:
            for k in range(w_len):
                aa_count[i][j[k]][k]+=1
            

    for i in Sec_Struct_list:
        for j in aa:
            for k in range(w_len):
                if(len(Sec_Struct_dict[i])>0):
                    P_tables[i][j][k]=aa_count[i][j][k]/len(Sec_Struct_dict[i])
                else:
                    P_tables[i][j][k]=0
    print(P_tables)
    return P_tables,class_p


P_tables,class_p= class_prob(sec_struct_dict,sec_struct_list)



Testclass=[[0 for i in range(len(sec_struct_list))] for j in range(len(Test_in))]
for i in range(len(Test_in)):
    for j in range(len(sec_struct_list)):
        sum=1
        for k in range(len(Test_in[i])):
            sum*=P_tables[sec_struct_list[j]][Test_in[i][k]][k]
        sum*=class_p[sec_struct_list[j]]
        Testclass[i][j]=sum
print(sec_struct_list)
count=0
for i in range(len(Test_in)):
    print(Test_in[i],Test_out[i],sec_struct_list[Testclass[i].index(max(Testclass[i]))])
    if(Test_out[i]==sec_struct_list[Testclass[i].index(max(Testclass[i]))]):
        count+=1
print("Accuracy is: ",count/len(Test_in))
