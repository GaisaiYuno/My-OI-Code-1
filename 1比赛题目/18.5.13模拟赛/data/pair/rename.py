import os
path = './'
for file in os.listdir(path):
    if os.path.isfile(os.path.join(path,file))==True:
        if file.find('.out')>=0:
            os.rename(os.path.join(path,file),os.path.join(path,file.replace(".out",".ans",6)))
            print file,'ok'
