# Registry Scanner

An advanced tool for detecting suspicious registry modifications on Windows.

---

## Scanned Areas

| Category | Path |
|---|---|
| Run / RunOnce / RunOnceEx | `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\{Run,RunOnce,RunOnceEx}` and `HKCU\...` |
| Winlogon Hijack | `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon` |
| AppInit_DLLs | `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows` and `HKLM\...\Wow6432Node\...` |
| IFEO Debugger Hijack | `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\<exe>` |
| Scheduled Task SD Deletion | `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\TaskCache\Tree\<Task>` |
| Scheduled Task COM Handlers | Via Task Scheduler COM API (`ITaskService`) |
| Prefetch Tampering | `HKLM\SYSTEM\{CurrentControlSet,ControlSet001}\Control\Session Manager\Memory Management\PrefetchParameters` |
| DisallowRun | `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\DisallowRun` and `HKCU\...` |
| Shell Verb Hijack | `HKCU/HKLM\SOFTWARE\Classes\<filetype>\shell\open\command` |
| COM CLSID Overrides | `HKCU\Software\Classes\CLSID` and `HKLM\SOFTWARE\Classes\CLSID` |
| Startup LNK Shortcuts | User Startup folder (`CSIDL_STARTUP`) |

---

## Status Flags

- **Clean** — key last-write is before or equal to boot time
- **Modified** — key was written after boot
- **Suspicious** — heuristic hit (e.g. Debugger value in IFEO, LOLBin from non-system path, EnablePrefetcher isn't 3, COM CLSID shadow attack, DisallowRun blocking security tools)

---

## Usage

1. Run the tool
2. Select scan categories on the startup screen
3. Click **Start Scan**
4. Filter by **All**, **Modified**, or **Suspicious only**
5. Click any row to open **Entry Detail** for per-key values
6. Right-click any row to copy the full registry path to clipboard or open in Registry Editor

---

## Notes

- Timestamps are shown in local time
- Boot anchor is determined via `NtQuerySystemInformation` (falls back to System process PID 4 if unavailable)
- All registry access is read-only — no keys or values are modified during scanning
- No network activity — all analysis is purely local
