# melonDS 1.1 한국어 패치 v1.2 (비공식)

melonDS 1.1 기반의 한국어 UI 패치입니다.

## 번역 및 수정 범위

- 기존 메인 메뉴와 화면 배치 선택지 번역 유지
- 기존 Wi-Fi 설정 설명 및 네트워크 모드 번역 유지
- 에뮬레이션, 오디오, 비디오, 인터페이스, 펌웨어 설정창 번역 보강
- 입력/단축키, 치트, 날짜/시간, LAN 및 넷플레이 대화상자 번역 보강
- RAM/ROM 정보, 전원 관리, 타이틀 관리 관련 대화상자 번역 보강
- 주요 툴팁과 안내 문구 번역 보강
- 메인 창 제목: `melonDS 1.1 -by 레쿠쟈`

## Windows x64 GitHub Actions 빌드

`.github/workflows/build-windows.yml` 워크플로를 사용합니다.

1. 저장소를 GitHub에 올립니다.
2. `Actions` 탭에서 `Windows` 워크플로를 선택합니다.
3. `Run workflow`로 수동 실행하거나 `main`/`master`에 push합니다.
4. 성공한 실행의 Artifacts에서 `melonDS-1.1-korean-windows-x64`를 받습니다.

현재 워크플로는 MSYS2 UCRT64 및 MinGW x64를 사용하며, vcpkg를 통해 의존성을 구성합니다.

## 빌드 검증 안내

이 ZIP은 전체 소스와 GitHub Actions 워크플로를 포함합니다. 이 작업 환경에서는 Windows x64 GitHub Actions 실행 결과를 직접 확인할 수 없으므로, 실제 컴파일 성공 여부는 저장소에 업로드한 뒤 Actions 결과로 확인해야 합니다.

## 라이선스

melonDS 원본 프로젝트의 GPL-3.0-or-later 라이선스 및 각 외부 구성 요소의 고지 사항을 따릅니다.
