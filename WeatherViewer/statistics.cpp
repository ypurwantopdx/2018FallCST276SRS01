#include "stdafx.h"
#include <iomanip>
#include "statistics.h"
#include "station.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics const& statistics)
    {
        auto const& station{ statistics.getStation() };

        auto const& begin{ statistics.getBegin() };
        auto const& now{ std::chrono::system_clock::now() };

        auto const meanTemperature{ station.getMeanTemperature(begin, now) };
        auto const meanHumidity{ station.getMeanHumidity(begin, now) };
        auto const meanPressure{ station.getMeanPressure(begin, now) };

        os <<
            std::setw(3) << meanTemperature.get() << " degree C, " <<
            std::setw(3) << meanHumidity.get()    << "%, "  <<
            std::setw(4) << meanPressure.get()    << " in. Hg";

        return os;
    }

    Statistics::Statistics(WeatherStation::Station const &station): station_{ station }
    {
    }

    WeatherStation::Station const& Statistics::getStation() const
    {
        return station_;
    }

    std::chrono::system_clock::time_point Statistics::getBegin() const
    {
        return begin_;
    }
}
