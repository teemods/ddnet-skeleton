import os

os.system('git remote add skeleton https://github.com/teemods/ddnet-skeleton')
os.system('git fetch skeleton')
os.system('git merge skeleton/main')
