// Copyright 2022 Gaming Research Integration for Learning Lab. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DISEnumsAndStructs.h"
#include "DISInterface.h"
#include "Engine/Datatable.h"
#include "DISClassEnumMappings.generated.h"

USTRUCT(BlueprintType)
struct FDISClassEnumStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GRILL DIS")
		FString FriendlyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MustImplement = "DISInterface"), Category = "GRILL DIS")
		TSoftClassPtr<AActor> DISEntity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GRILL DIS")
		TArray<FEntityType> AssociatedDISEnumerations;
};

/**
 * 
 */
UCLASS(BlueprintType)
class DISRUNTIME_API UDISClassEnumMappings : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere,	Meta = (DisplayName = "DIS Class Enumeration Mappings", Tooltip = "Mappings between DIS enumerations and associated actors.", TitleProperty = "FriendlyName"), Category = "GRILL DIS")
		TArray<FDISClassEnumStruct> DISClassEnumArray;
};
