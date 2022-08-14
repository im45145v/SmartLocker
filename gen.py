import cohere 
co = cohere.Client('az7h7eRodL0xIIvQs6rN7GgHpH7AxCQ0bTPPeftb') 
response = co.generate( 
  model='xlarge', 
  prompt='year:', 
  max_tokens=9, 
  temperature=1.3, 
  k=0,p=1,presence_penalty=0,frequency_penalty=0,
  stop_sequences=["--"], 
  return_likelihoods='NONE') 
str1=response.generations[0].text
str2=str1.split()
i=0
while i<4:
    x=len(str2[i])
    i=i+1
    print(x)
