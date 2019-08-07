print ("hello world")

import requests
import hashlib
import random

appid = '20180308000132782' #你的appid
secretKey = 'P3WnIy0BfrwmDDtgRjuE' #你的密钥

httpClient = None
myurl = 'http://api.fanyi.baidu.com/api/trans/vip/translate'
q = '你好'
fromLang = 'zh'
toLang = 'en'
salt = random.randint(32768, 65536)

sign = appid+q+str(salt)+secretKey
m1 = hashlib.md5()
m1.update(bytes(sign, encoding="utf-8"))
sign = m1.hexdigest()
myurl = myurl+'?appid='+appid+'&q='+q+'&from='+fromLang+'&to='+toLang+'&salt='+str(salt)+'&sign='+sign


result = requests.get(myurl)

print (result.content)

content = eval(result.content)["trans_result"]
dst = content[0]["dst"]
print (dst)
