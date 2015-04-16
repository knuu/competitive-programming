endic1 = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
endic2 = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
s = input()
if int(s) < 20:
    print(endic1[int(s)])
elif s[1] == '0':
    print(endic2[int(s[0])])
else:
    print(endic2[int(s[0])] + '-' + endic1[int(s[1])])
