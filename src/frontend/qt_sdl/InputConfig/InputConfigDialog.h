/*
    Copyright 2016-2025 melonDS team

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef INPUTCONFIGDIALOG_H
#define INPUTCONFIGDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <initializer_list>

#include "Config.h"
#include "EmuInstance.h"

static constexpr int keypad_num = 12;

static constexpr std::initializer_list<int> hk_addons =
{
    HK_SolarSensorIncrease,
    HK_SolarSensorDecrease,
    HK_GuitarGripGreen,
    HK_GuitarGripRed,
    HK_GuitarGripYellow,
    HK_GuitarGripBlue,
};

static constexpr std::initializer_list<const char*> hk_addons_labels =
{
    "[보쿠타이] 태양광 + ",
    "[보쿠타이] 태양광 - ",
    "[기타 그립] 초록",
    "[기타 그립] 빨강",
    "[기타 그립] 노랑",
    "[기타 그립] 파랑",
};

static_assert(hk_addons.size() == hk_addons_labels.size());

static constexpr std::initializer_list<int> hk_general =
{
    HK_Pause,
    HK_Reset,
    HK_FrameStep,
    HK_FastForward,
    HK_FastForwardToggle,
    HK_SlowMo,
    HK_SlowMoToggle,
    HK_FrameLimitToggle,
    HK_FullscreenToggle,
    HK_Lid,
    HK_Mic,
    HK_SwapScreens,
    HK_SwapScreenEmphasis,
    HK_PowerButton,
    HK_VolumeUp,
    HK_VolumeDown
};

static constexpr std::initializer_list<const char*> hk_general_labels =
{
    "일시정지/재개",
    "초기화",
    "프레임 단위 진행",
    "빨리 감기",
    "빨리 감기 전환",
    "슬로 모션",
    "슬로 모션 전환",
    "FPS 제한 전환",
    "전체 화면 전환",
    "덮개 닫기/열기",
    "마이크",
    "화면 순서 바꾸기",
    "화면 강조 전환",
    "DSi 전원 버튼",
    "DSi 음량 높이기",
    "DSi 음량 낮추기"
};

static_assert(hk_general.size() == hk_general_labels.size());


namespace Ui { class InputConfigDialog; }
class InputConfigDialog;

class InputConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputConfigDialog(QWidget* parent);
    ~InputConfigDialog();

    SDL_Joystick* getJoystick();
    std::shared_ptr<SDL_mutex> getJoyMutex();

    static InputConfigDialog* currentDlg;
    static InputConfigDialog* openDlg(QWidget* parent)
    {
        if (currentDlg)
        {
            currentDlg->activateWindow();
            return currentDlg;
        }

        currentDlg = new InputConfigDialog(parent);
        currentDlg->open();
        return currentDlg;
    }
    static void closeDlg()
    {
        currentDlg = nullptr;
    }

private slots:
    void on_InputConfigDialog_accepted();
    void on_InputConfigDialog_rejected();

    void on_btnKeyMapSwitch_clicked();
    void on_btnJoyMapSwitch_clicked();
    void on_cbxJoystick_currentIndexChanged(int id);

private:
    void populatePage(QWidget* page,
        const std::initializer_list<const char*>& labels,
        int* keymap, int* joymap);
    void setupKeypadPage();

    Ui::InputConfigDialog* ui;

    EmuInstance* emuInstance;

    int keypadKeyMap[12], keypadJoyMap[12];
    int addonsKeyMap[hk_addons.size()], addonsJoyMap[hk_addons.size()];
    int hkGeneralKeyMap[hk_general.size()], hkGeneralJoyMap[hk_general.size()];
    int joystickID;
};


#endif // INPUTCONFIGDIALOG_H
