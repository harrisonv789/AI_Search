// FIT3094 - Assignment 1
// Harrison Verrios

#include "A1_SearchGameModeBase.h"
#include "Misc/FileHelper.h"

TArray<FString> AA1_SearchGameModeBase::GetMapFileList()
{
	TArray<FString> MapFiles;

	const FString MapsDir = FPaths::ProjectContentDir() + "MapFiles/";
	FPlatformFileManager::Get().GetPlatformFile().FindFiles(MapFiles, *MapsDir, nullptr);

	return MapFiles;
}

FString AA1_SearchGameModeBase::GetRandomMapText()
{
	TArray<FString> MapFiles = GetMapFileList();

	int32 MapPosition = FMath::RandRange(0, MapFiles.Num() - 1);
	FString MapPath = MapFiles[MapPosition];

	FString MapText;
	FFileHelper::LoadFileToString(MapText, *MapPath);

	return MapText;
}

TArray<FString> AA1_SearchGameModeBase::GetMapArray()
{
	TArray<FString> MapArray;

	FString MapText = GetRandomMapText();
	MapText.ParseIntoArrayLines(MapArray);

	return MapArray;
}
