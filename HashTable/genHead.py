#encoding:utf-8
import sys

def main():
	if len(sys.argv) == 2:
		fileName = sys.argv[1]
	else:
		fileName = 'stdafx.cpp'
	
	print 'fileName: '+ fileName
	contents = readFile(fileName)
	startPos = findStart(contents)
	newFile = open('output.h','w')
	heads = getHead(contents[startPos:])
	newFile.writelines(heads)
	newFile.close()
	print 'Finshed!'



def readFile(fileName):
	try:
		file = open(fileName)
		contents = file.readlines()
		file.close()
		return contents
	except Exception, e:
		print '文件名错误'
		exit(-1)

def findStart(contents):
	startPos = 0 #起始位置为0行
	isFindFirstPound = False #是否找到第一个'＃'
	while True:
		if contents[startPos][0] == '#':
			if not isFindFirstPound:
				if contents[startPos][0] == '#':
					isFindFirstPound = True
		else:
			if isFindFirstPound:
				return startPos
		startPos += 1

def getHead(contents):
	isStart = False
	isEnd = False
	heads = []
	for line in contents:
		if line[0] == '/' and line[1] == '*':
			if not isStart:
				isStart = True
				isEnd = False
				heads.append(line)
			else:
				pass
		elif line[0] == '{':
			if isEnd:#已经结束函数头部
				pass
			else:
				isEnd = True
				isStart = False
				pre = heads[-1]
				print unicode(pre)
				heads[-1] = pre[:-1] + ';\n\n'
		else:
			if isStart and not isEnd:
				heads.append(line)
			else:
				pass

	return heads



main()
		
