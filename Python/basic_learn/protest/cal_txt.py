import jieba

excludes  = {"the","and","of","you","a","i","my","in","将军","却说","丞相"} # out 

def get_Hamlet_Text():
    counts = {} # 添加字典的初始化操作
    with open ("/Users/chen/python/test_/test_06/other_files/hamlet.txt","r") as f:
        #read only 
        txt = f.read()
        txt = txt.lower()
        for ch in '!"#$%&()*+,-/.:;<>=?@[\\]^_{|}~':
            txt.replace(ch," ")
        words = txt.split()
        for word in words:
            counts[word] =counts.get(word , 0) +1
    return counts

def get_Romance_of_Three_Kindoms():
    counts = {} # 添加字典的初始化操作
    with open("./files/sgyy.txt","r",encoding='utf-8') as f :
        txt = f.read()
        #read only 
        words = jieba.lcut(txt) # 修改jiebaa为jieba
        for word in words:
            if len(word)==1:
                continue
            else:
                counts[word] = counts.get(word,0)+1
    return counts

#counts = get_Hamlet_Text()
counts = get_Romance_of_Three_Kindoms()

for word in excludes:     #del out
    del counts[word]   # 修改字典删除操作

items = list (counts.items())
items.sort(key = lambda x:x[1], reverse = True)

for i in range(15):
    word,count = items[i]
    print("{0:<10}{1:>5}".format(word,count))