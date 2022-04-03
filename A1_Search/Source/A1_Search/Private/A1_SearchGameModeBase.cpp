// FIT3094 - Assignment 1
// Harrison Verrios

#include "A1_SearchGameModeBase.h"
#include "Misc/FileHelper.h"

TArray<FString> AA1_SearchGameModeBase::GetMapFileList()
{
	TArray<FString> mapFiles;

	const FString mapsDir = FPaths::ProjectContentDir() + "MapFiles/";
	FPlatformFileManager::Get().GetPlatformFile().FindFiles(mapFiles, *mapsDir, nullptr);

	return mapFiles;
}

FString AA1_SearchGameModeBase::GetRandomMapText()
{
	TArray<FString> mapFiles = GetMapFileList();

	int32 mapPosition = FMath::RandRange(0, mapFiles.Num() - 1);
	FString mapPath = mapFiles[mapPosition];

	FString mapText;
	FFileHelper::LoadFileToString(mapText, *mapPath);

	return mapText;
}

TArray<FString> AA1_SearchGameModeBase::GetMapArray()
{
	TArray<FString> mapArray;

	FString mapText = GetRandomMapText();
	mapText.ParseIntoArrayLines(mapArray);

	return mapArray;
}
