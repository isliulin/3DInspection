#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <QSettings>
#include <QFile>

#include "../sdk/customexception.hpp"
#include "../sdk/formatconvertion.hpp"

namespace App
{
    //软件的主题为枚举类型,其值为Black,White
    enum class THEME
    {
        BLACK ,
        WHITE
    };
    //软件的语言为枚举类型,其值为CN,EN
    enum class LANG
    {
        CN,
        EN
    };
    //软件的工作的模式为枚举类型,其值为 Simulator, SingleLane, DualLane
    enum class LANEMODE
    {
        SIMULATOR,
        SINGLE_LANE,
        DUAN_LANE
    };
    //设备的工作模式为枚举类型,其值为SPI,AOI
    enum class MACHINETYPE
    {
        SPI,
        AOI
    };

    /**
     *  @brief AppSetting
     *         读取目录下的配置文件,如果目录下没有配置文件,则自动生成默认值
     *         如果目录下文件数据信息不正确,则将文件数据写如默认值
     *  @author bob
     *  @version 1.00 2017-11-21 bob
     *                note:create it
     */
    class AppSetting
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //析构 & 构造函数
        AppSetting();

        ~AppSetting();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //成员变量
        THEME m_theme;               //软件主题,(有BLACK & WHITE两种)
        LANG m_lang;                 //软件语言,(有CN & EN 两种)
        //软件运行模式(有SIMULATOR(离线),SINGLELANE(单轨模式),DUANLANE(双轨模式))
        LANEMODE m_laneMode;
        MACHINETYPE m_machineType;  //设备的工作模式(SPI(检测锡膏),AOI(检测贴片元件))
        std::string m_companyName;  //公司名称,(目前有Scijet,Sung两种)
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //读写配置文件中的数据
        /*
        *  @brief  readAppSetting
        *          读取指定目录下的文件,判断文件目录是否存在,则写入默认配置文件
        *          如果文件数据不正确,则将数据写入默认值
        *  @param  path:读取文件的路径,如(./app.ini)
        *  @return  N/A
        */
        void readAppSetting(const QString& path);

        /*
        *  @brief  writeAppSetting
        *          将根据数据格式将数据写入指定路径下的文件
        *  @param  path:写入数据文件的路径,如(./app.ini)
        *  @return  N/A
        */
        void writeAppSetting(const QString& path);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    };
} //End of namespace App

#endif // APPSETTING_HPP
