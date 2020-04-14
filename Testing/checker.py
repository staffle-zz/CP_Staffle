from os import popen

for i in range(100):
    print i
    f = open('test.txt', 'w')
    test = popen('./generator').read();
    f.write(test)
    f.close()
    v1 = popen('./a < test.txt').read()
    v2 = popen('./a_good < test.txt').read()
    if v1 != v2:
        print "TEST"
        print test
        print "GOOD"
        print v1
        print "BAD"
        print v2
        break