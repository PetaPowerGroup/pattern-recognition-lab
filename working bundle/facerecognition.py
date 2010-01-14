# To change this template, choose Tools | Templates
# and open the template in the editor.

__author__="kermit"
__date__ ="$2010.01.12 21:00:55$"

import re
import subprocess

#
# ------------------------------------------
#

def remove_newline_from_strings(targetList):
    newList=[]
    for element in targetList:
        #print "element is " + element
        if element.find("\n")>0:
            newList.append(element.split("\n")[0])
        else:
            newList.append(element)
    return newList

def remove_comments_and_newlines_from(targetList):
    newList=[]
    comment=re.compile("#.*")
    empty=re.compile("\n")
    for element in targetList:
        #print "element is " + element
        if not (comment.match(element) or empty.match(element)):
            newList.append(element)
    return newList


class Application:
    folderLocation=""

    scaleCommand=""
    classifier=""
    libsvmTrainCommand=""
    kreshvmParameterC=1
    kreshvmParameterType=2
    kreshvmParameterThird=3
    kreshvmTestCommand=""
    dataDivisionCommand=""

    featureExtractionMethod=2
    haarWindowWidth=8
    haarWindowHeight=8
    finalNumberOfPCAFeatures=30
    numberOfPeople=294

    def calculate_number_of_features(self, filename):
        maxFeatures=0
        featuresFile=open(filename, "r")
        featuresString=featuresFile.readline()
        print featuresString
        while featuresString:
            listOfFeatures=featuresString.split(" ")
            if len(listOfFeatures)>maxFeatures:
                maxFeatures=len(listOfFeatures)
            featuresString=featuresFile.readline()
        featuresFile.close()
        return maxFeatures-2


    def read_from_conf_file(self):
        configFile=open('conf-file.txt', 'r')
        configLines = configFile.readlines()
        configLines=remove_newline_from_strings(configLines)
        configLines=remove_comments_and_newlines_from(configLines)

        self.folderLocation=configLines[0]
        print "Folder location is " + self.folderLocation

        self.scaleCommand=configLines[1]

        self.classifier=configLines[2]

        self.libsvmTrainCommand=configLines[3]

        self.kreshvmParameterC=float(configLines[4])

        self.kreshvmParameterType=float(configLines[5])

        self.kreshvmParameterThird=float(configLines[6])

        self.kreshvmTestCommand=configLines[7]

        self.dataDivisionCommand=configLines[8]


        self.featureExtractionMethod=configLines[9]
        self.haarWindowWidth=configLines[10]
        self.haarWindowHeight=configLines[11]
        self.finalNumberOfPCAFeatures=configLines[12]
        self.numberOfPeople=configLines[13]

#if __name__ == "__main__":
#    read_from_conf_file()
#
#
#    if callSonicAnnotator==1:
#        # extract actual songs' genres and write them to file
#        outputFile=open(outputFileName, "w")
#        print classificationTestMethod
#        if classificationTestMethod=="folder":
#            determine_class_from_folder_name(folderLocation, outputFile)
#        else:
#            if classificationTestMethod=="id3":
#                recursively_determine_class_from_id3(folderLocation, outputFile)
#        outputFile.close()
#
#        # extract features
#        print "calling sonic annotator to extract features..."
#        #print os.path.join(os.getcwd(),sonicAnnotatorCommand + " " + folderLocation)
#        #subprocess.call(os.path.join(os.getcwd(),sonicAnnotatorCommand + " " + folderLocation), shell=True)
#        print "command: "+ sonicAnnotatorCommand
#        subprocess.call(sonicAnnotatorCommand + " " + folderLocation, shell=True)
#    else:
#        print "will try to use existing features..."
#        # copy existing features from last_session to root
#
#    # format file
#    print "uzorci.exe\nformating file..."
#    subprocess.call("uzorci.exe", shell=True)
#    # empty last_session
#    # copy all .csv files and uzorci_razred.txt from root to last_session
#
#    # calling the classifier
#    if classifier=="libsvm":
#        # using libsvm classifier
#        # scale data
#        print "command: "+ scaleCommand+"\nscaling data..."
#        subprocess.call(scaleCommand + " skup_svih_znacajki.txt > skaliran_skup_svih_znacajki.txt", shell=True)
#        # train and validate classifier
#        print "command: "+ libsvmTrainCommand+"\ntraining and validating..."
#        subprocess.call(libsvmTrainCommand + " skaliran_skup_svih_znacajki.txt", shell=True)
#
#    elif classifier=="kreshvm":
#        # using our classifier "kreshvm"
#        # divide data
#        subprocess.call(dataDivisionCommand, shell=True)
#
#        # scale training data
#        subprocess.call(scaleCommand + " skup_za_ucenje.txt > skaliran_skup_za_ucenje.txt", shell=True)
#        subprocess.call("del skup_za_ucenje.txt", shell=True)
#        subprocess.call("rename skaliran_skup_za_ucenje.txt skup_za_ucenje.txt", shell=True)
#        #rename("skaliran_skup_za_ucenje.txt", "skup_za_ucenje.txt")
#
#        # scale testing data
#        subprocess.call(scaleCommand + " skup_za_testiranje.txt > skaliran_skup_za_testiranje.txt", shell=True)
#        subprocess.call("del skup_za_testiranje.txt", shell=True)
#        subprocess.call("rename skaliran_skup_za_testiranje.txt skup_za_testiranje.txt", shell=True)
#        #rename("skaliran_skup_za_testiranje.txt", "skup_za_testiranje.txt")
#
#        # train the svm
#        numberOfFeatures=calculate_number_of_features("skup_svih_znacajki.txt")
#        kreshvmTrainCommand="kreshvm_train.exe " + str(numberOfFeatures) + " " + str(kreshvmParameterC) + " " + str(kreshvmParameterType)
#        if not kreshvmParameterType==1:
#            kreshvmTrainCommand= kreshvmTrainCommand + " " + str(kreshvmParameterThird)
#        print "command: "+ kreshvmTrainCommand +"\ntraining kreshvm..."
#        subprocess.call(kreshvmTrainCommand, shell=True)
#
#        # test the efficiency of the svm
#        print "command: "+ kreshvmTestCommand+"\ntesting kreshvm..."
#        subprocess.call(kreshvmTestCommand, shell=True)
#
#        # delete unneccesary files


    def run(self):

        ##
        ## extract features
        ##

        featureExtractorCommand="feature_extractor.exe "+app.folderLocation+" "+str(app.featureExtractionMethod)
        featureExtractorCommand=featureExtractorCommand+" "+str(app.haarWindowWidth)+" "+str(app.haarWindowHeight)
        featureExtractorCommand=featureExtractorCommand+" "+str(app.finalNumberOfPCAFeatures)+" "+str(app.numberOfPeople)
        print "extracting features with command " + featureExtractorCommand
        print featureExtractorCommand

        subprocess.call(featureExtractorCommand, shell=True)

        ##
        ## format, train classifier and test classification
        ##

        # format file
        print "uzorci.exe\nformating file..."
        subprocess.call("uzorci.exe", shell=True)
        # empty last_session
        # copy all .csv files and uzorci_razred.txt from root to last_session

        # calling the classifier
        if self.classifier=="libsvm":
            # using libsvm classifier
            # scale data
            print "command: "+ self.scaleCommand+"\nscaling data..."
            subprocess.call(self.scaleCommand + " skup_svih_znacajki.txt > skaliran_skup_svih_znacajki.txt", shell=True)
            # train and validate classifier
            print "command: "+ self.libsvmTrainCommand+"\ntraining and validating..."
            subprocess.call(self.libsvmTrainCommand + " skaliran_skup_svih_znacajki.txt", shell=True)

        elif self.classifier=="kreshvm":
            # using our classifier "kreshvm"
            # divide data
            subprocess.call(self.dataDivisionCommand, shell=True)

            # scale training data
            subprocess.call(self.scaleCommand + " skup_za_ucenje.txt > skaliran_skup_za_ucenje.txt", shell=True)
            subprocess.call("del skup_za_ucenje.txt", shell=True)
            subprocess.call("rename skaliran_skup_za_ucenje.txt skup_za_ucenje.txt", shell=True)
            #rename("skaliran_skup_za_ucenje.txt", "skup_za_ucenje.txt")

            # scale testing data
            subprocess.call(self.scaleCommand + " skup_za_testiranje.txt > skaliran_skup_za_testiranje.txt", shell=True)
            subprocess.call("del skup_za_testiranje.txt", shell=True)
            subprocess.call("rename skaliran_skup_za_testiranje.txt skup_za_testiranje.txt", shell=True)
            #rename("skaliran_skup_za_testiranje.txt", "skup_za_testiranje.txt")

            # train the svm
            numberOfFeatures=self.calculate_number_of_features("skup_svih_znacajki.txt")
            kreshvmTrainCommand="kreshvm_train.exe " + str(numberOfFeatures) + " " + str(self.kreshvmParameterC) + " " + str(self.kreshvmParameterType)
            if not self.kreshvmParameterType==1:
                kreshvmTrainCommand= self.kreshvmTrainCommand + " " + str(self.kreshvmParameterThird)
            print "command: "+ kreshvmTrainCommand +"\ntraining kreshvm..."
            subprocess.call(kreshvmTrainCommand, shell=True)

            # test the efficiency of the svm
            print "command: "+ self.kreshvmTestCommand+"\ntesting kreshvm..."
            subprocess.call(self.kreshvmTestCommand, shell=True)



if __name__ == "__main__":
    app=Application()
    app.read_from_conf_file()
    app.run()

    