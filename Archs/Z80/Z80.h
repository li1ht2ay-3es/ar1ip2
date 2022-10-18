#pragma once

#include "Archs/Architecture.h"

class Expression;

enum Z80ArchType { MARCH_Z80 = 0, MARCH_Gameboy, MARCH_Ereader, MARCH_Invalid };

class CZ80Architecture: public Architecture
{
public:
	CZ80Architecture();
	virtual std::unique_ptr<CAssemblerCommand> parseDirective(Parser& parser);
	virtual std::unique_ptr<CAssemblerCommand> parseOpcode(Parser& parser);
	virtual void registerExpressionFunctions(ExpressionFunctionHandler &handler) { return; };
	virtual void NextSection() { return; };
	virtual void Pass2() { return; };
	virtual void Revalidate() { return; };
	virtual std::unique_ptr<IElfRelocator> getElfRelocator();
	virtual Endianness getEndianness() { return Endianness::Little; };
	virtual int getWordSize() { return 2; };
	void SetVersion(Z80ArchType v) { Version = v; };
	Z80ArchType GetVersion() { return Version; };
	const std::string GetName() {
		switch (Version)
		{
		case Z80ArchType::MARCH_Gameboy:
			return "Gameboy";
		case Z80ArchType::MARCH_Ereader:
			return "e-Reader";
		default:
			return "Z80";
		}
	}
private:
	Z80ArchType Version;
};

struct Z80RegisterValue
{
	std::string name;
	int64_t num;
};

extern CZ80Architecture Z80;
