#pragma once
#include "MyHeader.h"
#include <string>
#include <ShlObj.h>
#include <KnownFolders.h>
#include <filesystem>

constexpr auto TRIendl = "\n\n\n";

std::wstring PathToTheFolder();

void Remover();

bool Answer();

void ToDo();
