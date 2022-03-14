import os

os.system('git remote add ddnet https://github.com/ddnet/ddnet')
os.system('git fetch ddnet')
os.system('git merge ddnet/master')