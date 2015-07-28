##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Complex
ConfigurationName      :=Debug
WorkspacePath          := "/home/ari/development/SoftwareLabs"
ProjectPath            := "/home/ari/development/SoftwareLabs/Complex"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ari Croock
Date                   :=28/07/15
CodeLitePath           :="/home/ari/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Complex.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ --std=gnu++14 -Wall
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/quadratic.cpp$(ObjectSuffix) $(IntermediateDirectory)/complex.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/quadratic.cpp$(ObjectSuffix): quadratic.cpp $(IntermediateDirectory)/quadratic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ari/development/SoftwareLabs/Complex/quadratic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/quadratic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/quadratic.cpp$(DependSuffix): quadratic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/quadratic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/quadratic.cpp$(DependSuffix) -MM "quadratic.cpp"

$(IntermediateDirectory)/quadratic.cpp$(PreprocessSuffix): quadratic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/quadratic.cpp$(PreprocessSuffix) "quadratic.cpp"

$(IntermediateDirectory)/complex.cpp$(ObjectSuffix): complex.cpp $(IntermediateDirectory)/complex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ari/development/SoftwareLabs/Complex/complex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/complex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/complex.cpp$(DependSuffix): complex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/complex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/complex.cpp$(DependSuffix) -MM "complex.cpp"

$(IntermediateDirectory)/complex.cpp$(PreprocessSuffix): complex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/complex.cpp$(PreprocessSuffix) "complex.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


