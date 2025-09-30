#include <playapi/device_info.h>

#include <sstream>
#include <iomanip>
#include <climits>
#include <cassert>
#include <gsf.pb.h>
#include <playapi/util/config.h>
#include <playapi/util/rand.h>

using namespace playapi;

device_type playapi::device_type_from_string(const std::string& str) {
    if (str == "phone")
        return device_type::phone;
    if (str == "tablet")
        return device_type::tablet;
    if (str == "tv")
        return device_type::tv;
    if (str == "glass")
        return device_type::glass;
    if (str == "wearable")
        return device_type::wearable;
    return device_type::unknown;
}
std::string playapi::device_type_to_string(device_type type) {
    switch (type) {
        case device_type::phone:
            return "phone";
        case device_type::tablet:
            return "tablet";
        case device_type::tv:
            return "tv";
        case device_type::glass:
            return "glass";
        case device_type::wearable:
            return "wearable";
        default:
            return "unknown";
    }
}

device_touch_screen playapi::device_touch_screen_from_string(const std::string& str) {
    if (str == "notouch")
        return device_touch_screen::notouch;
    if (str == "stylus")
        return device_touch_screen::stylus;
    if (str == "finger")
        return device_touch_screen::finger;
    return device_touch_screen::undefinied;
}
std::string playapi::device_touch_screen_to_string(device_touch_screen type) {
    switch (type) {
        case device_touch_screen::notouch:
            return "notouch";
        case device_touch_screen::stylus:
            return "stylus";
        case device_touch_screen::finger:
            return "finger";
        default:
            return "undefinied";
    }
}

device_keyboard playapi::device_keyboard_from_string(const std::string& str) {
    if (str == "nokeys")
        return device_keyboard::nokeys;
    if (str == "qwerty")
        return device_keyboard::qwerty;
    if (str == "twelvekey")
        return device_keyboard::twelvekey;
    return device_keyboard::undefinied;
}
std::string playapi::device_keyboard_to_string(device_keyboard type) {
    switch (type) {
        case device_keyboard::nokeys:
            return "nokeys";
        case device_keyboard::qwerty:
            return "qwerty";
        case device_keyboard::twelvekey:
            return "twelvekey";
        default:
            return "undefinied";
    }
}

device_navigation playapi::device_navigation_from_string(const std::string& str) {
    if (str == "nonav")
        return device_navigation::nonav;
    if (str == "dpad")
        return device_navigation::dpad;
    if (str == "trackball")
        return device_navigation::trackball;
    if (str == "wheel")
        return device_navigation::wheel;
    return device_navigation::undefinied;
}
std::string playapi::device_navigation_to_string(device_navigation type) {
    switch (type) {
        case device_navigation::nonav:
            return "nonav";
        case device_navigation::dpad:
            return "dpad";
        case device_navigation::trackball:
            return "trackball";
        case device_navigation::wheel:
            return "wheel";
        default:
            return "undefinied";
    }
}

device_screen_layout playapi::device_screen_layout_from_string(const std::string& str) {
    if (str == "small")
        return device_screen_layout::small;
    if (str == "normal")
        return device_screen_layout::normal;
    if (str == "large")
        return device_screen_layout::large;
    if (str == "xlarge")
        return device_screen_layout::xlarge;
    return device_screen_layout::undefinied;
}
std::string playapi::device_screen_layout_to_string(device_screen_layout type) {
    switch (type) {
        case device_screen_layout::small:
            return "small";
        case device_screen_layout::normal:
            return "normal";
        case device_screen_layout::large:
            return "large";
        case device_screen_layout::xlarge:
            return "xlarge";
        default:
            return "undefinied";
    }
}

device_info::device_info() {
    std::vector<std::string> features = {"android.hardware.sensor.proximity", "com.google.android.feature.CONTEXTUAL_SEARCH", "com.verizon.hardware.telephony.lte", "com.google.android.feature.PIXEL_2024_EXPERIENCE", "com.verizon.hardware.telephony.ehrpd", "android.hardware.telephony.ims.singlereg", "android.hardware.sensor.accelerometer", "android.software.controls", "android.hardware.faketouch", "android.software.telecom", "android.hardware.telephony.subscription", "com.google.android.feature.D2D_CABLE_MIGRATION_FEATURE", "android.hardware.telephony.euicc", "android.hardware.usb.accessory", "android.hardware.telephony.data", "android.hardware.sensor.dynamic.head_tracker", "android.software.backup", "android.hardware.touchscreen", "android.hardware.touchscreen.multitouch", "android.software.erofs", "android.software.print", "android.software.activities_on_secondary_displays", "android.hardware.wifi.rtt", "com.android.systemui.SUPPORTS_DRAG_ASSISTANT_TO_SPLIT", "android.software.device_lock", "com.google.android.feature.PIXEL_2017_EXPERIENCE", "com.google.android.feature.PIXEL_2024_MIDYEAR_EXPERIENCE", "android.software.voice_recognizers", "android.software.picture_in_picture", "android.hardware.fingerprint", "android.hardware.telephony.satellite", "android.hardware.sensor.gyroscope", "android.hardware.audio.low_latency", "android.software.vulkan.deqp.level", "android.software.cant_save_state", "com.google.android.feature.PIXEL_2018_EXPERIENCE", "android.hardware.security.model.compatible", "android.hardware.telephony.messaging", "com.google.android.feature.PIXEL_2019_EXPERIENCE", "android.hardware.telephony.calling", "android.hardware.opengles.aep", "android.hardware.bluetooth", "com.google.android.feature.PIXEL_2023_MIDYEAR_EXPERIENCE", "android.software.window_magnification", "android.hardware.telephony.radio.access", "android.hardware.camera.autofocus", "com.google.android.feature.GOOGLE_BUILD", "android.hardware.telephony.gsm", "android.hardware.telephony.ims", "android.software.incremental_delivery", "android.hardware.se.omapi.ese", "android.software.opengles.deqp.level", "vendor.android.hardware.camera.preview-dis.front", "com.google.android.feature.PIXEL_2022_MIDYEAR_EXPERIENCE", "android.hardware.camera.concurrent", "android.hardware.usb.host", "android.hardware.audio.output", "android.software.ipsec_tunnel_migration", "android.software.verified_boot", "android.hardware.camera.flash", "android.hardware.camera.front", "android.hardware.sensor.hifi_sensors", "android.hardware.se.omapi.uicc", "android.hardware.strongbox_keystore", "android.hardware.screen.portrait", "android.hardware.nfc", "com.google.android.feature.TURBO_PRELOAD", "com.nxp.mifare", "com.google.android.feature.PIXEL_2021_MIDYEAR_EXPERIENCE", "android.hardware.sensor.stepdetector", "android.software.home_screen", "android.hardware.context_hub", "vendor.android.hardware.camera.preview-dis.back", "android.hardware.microphone", "android.software.autofill", "android.software.securely_removes_users", "com.google.android.feature.PIXEL_EXPERIENCE", "android.hardware.bluetooth_le", "android.hardware.sensor.compass", "com.google.android.feature.GOOGLE_FI_BUNDLED", "android.hardware.touchscreen.multitouch.jazzhand", "android.hardware.sensor.barometer", "android.software.app_widgets", "com.google.android.feature.PIXEL_2020_MIDYEAR_EXPERIENCE", "android.software.sdksandbox.sdk_install_work_profile", "android.hardware.telephony.carrierlock", "android.software.input_methods", "android.hardware.sensor.light", "android.hardware.vulkan.version", "android.software.companion_device_setup", "android.software.device_admin", "com.google.android.feature.WELLBEING", "android.hardware.wifi.passpoint", "android.hardware.camera", "android.software.credentials", "android.hardware.device_unique_attestation", "android.hardware.screen.landscape", "android.software.device_id_attestation", "com.google.android.feature.AER_OPTIMIZED", "android.hardware.ram.normal", "com.google.android.feature.NEXT_GENERATION_ASSISTANT", "com.google.android.feature.PIXEL_2019_MIDYEAR_EXPERIENCE", "android.software.managed_users", "android.software.webview", "android.hardware.sensor.stepcounter", "android.hardware.camera.capability.manual_post_processing", "android.hardware.camera.any", "android.hardware.camera.capability.raw", "android.hardware.vulkan.compute", "android.hardware.touchscreen.multitouch.distinct", "android.hardware.location.network", "android.software.cts", "android.hardware.camera.capability.manual_sensor", "android.software.app_enumeration", "com.google.android.apps.dialer.SUPPORTED", "android.hardware.camera.level.full", "com.google.android.feature.GMS_GAME_SERVICE", "android.software.game_service", "android.hardware.wifi.direct", "android.software.live_wallpaper", "com.google.android.feature.GOOGLE_EXPERIENCE", "android.software.ipsec_tunnels", "com.google.android.feature.EXCHANGE_6_2", "com.google.android.feature.DREAMLINER", "android.hardware.audio.pro", "android.hardware.nfc.hcef", "android.hardware.location.gps", "com.google.android.feature.ADAPTIVE_CHARGING", "android.software.midi", "android.hardware.nfc.any", "android.hardware.nfc.ese", "android.hardware.nfc.hce", "android.hardware.hardware_keystore", "com.google.android.feature.PIXEL_2020_EXPERIENCE", "android.hardware.telephony.euicc.mep", "android.hardware.wifi", "android.hardware.location", "android.hardware.vulkan.level", "android.software.virtualization_framework", "com.google.android.feature.PIXEL_2021_EXPERIENCE", "android.hardware.keystore.app_attest_key", "com.google.android.feature.QUICK_TAP", "android.software.wallet_location_based_suggestions", "android.hardware.wifi.aware", "com.google.android.feature.PIXEL_2022_EXPERIENCE", "android.software.secure_lock_screen", "android.hardware.biometrics.face", "com.google.android.feature.PIXEL_2023_EXPERIENCE", "android.hardware.telephony", "android.software.file_based_encryption"};
    for (const std::string& feature : features)
        config_system_features.push_back({feature, 0});
}

void device_info::load(config& conf) {
    type = device_type_from_string(conf.get("device_type", device_type_to_string(type)));
    build_fingerprint = conf.get("build.fingerprint", build_fingerprint);
    build_id = conf.get("build.id", build_id);
    build_product = conf.get("build.product", build_product);
    build_brand = conf.get("build.brand", build_brand);
    build_radio = conf.get("build.radio", build_radio);
    build_bootloader = conf.get("build.bootloader", build_bootloader);
    build_client = conf.get("build.client", build_client);
    build_timestamp = conf.get_long("build.timestamp", build_timestamp);
    vending_version = conf.get_int("vending.version", vending_version);
    vending_version_string = conf.get("vending.version_string", vending_version_string);
    build_device = conf.get("build.device", build_device);
    build_sdk_version = conf.get_int("build.sdk_version", build_sdk_version);
    build_version_string = conf.get("build.version_string", build_version_string);
    build_model = conf.get("build.model", build_model);
    build_manufacturer = conf.get("build.manufacturer", build_manufacturer);
    build_build_product = conf.get("build.build_product", build_build_product);
    build_ota_installed = conf.get_bool("build.ota_installed", build_ota_installed);
    auto pkgs_list = conf.get_array("build.google_packages");
    if (pkgs_list.size() > 0) {
        build_google_packages.clear();
        for (const auto& pkg : pkgs_list) {
            auto iof = pkg.find(':');
            if (iof == std::string::npos)
                continue;
            build_google_packages.push_back({pkg.substr(0, iof), std::stoi(pkg.substr(iof + 1))});
        }
    }
    build_security_patch = conf.get("build.security_patch", build_security_patch);

    config_touch_screen = device_touch_screen_from_string(
            conf.get("config.touch_screen", device_touch_screen_to_string(config_touch_screen)));
    config_keyboard = device_keyboard_from_string(
            conf.get("config.keyboard", device_keyboard_to_string(config_keyboard)));
    config_navigation = device_navigation_from_string(
            conf.get("config.navigation", device_navigation_to_string(config_navigation)));
    config_screen_layout = device_screen_layout_from_string(
            conf.get("config.screen_layout", device_screen_layout_to_string(config_screen_layout)));
    config_has_hard_keyboard = conf.get_bool("config.has_hard_keyboard", config_has_hard_keyboard);
    config_has_five_way_navig = conf.get_bool("config.has_five_way_navig", config_has_five_way_navig);
    config_screen_density = conf.get_int("config.screen_density", config_screen_density);
    config_gles_version = conf.get_int("config.gles_version", config_gles_version);
    config_system_shared_libraries = conf.get_array("config.system_shared_libraries", config_system_shared_libraries);
    auto features_list = conf.get_array("config.system_features");
    if (features_list.size() > 0) {
        config_system_features.clear();
        for (const auto& feature : features_list) {
            std::string name = feature;
            int gles_ver = 0;
            auto iof = name.find(':');
            if (iof != std::string::npos) {
                gles_ver = std::stoi(name.substr(iof + 1));
                name = name.substr(0, iof);
            }
            config_system_features.push_back({name, gles_ver});
        }
    }
    config_native_platforms = conf.get_array("config.native_platforms", config_native_platforms);
    config_screen_width = conf.get_int("config.screen_width", config_screen_width);
    config_screen_height = conf.get_int("config.screen_height", config_screen_height);
    config_system_supported_locales = conf.get_array("config.system_supported_locales",
                                                     config_system_supported_locales);
    config_gl_extensions = conf.get_array("config.gl_extensions", config_gl_extensions);
    config_smallest_screen_width_dp = conf.get_int("config.smallest_screen_width_dp", config_smallest_screen_width_dp);
    config_low_ram = conf.get_bool("config.low_raw", config_low_ram);
    config_total_ram = conf.get_long("config.total_ram", config_total_ram);
    config_cores = conf.get_int("config.cores", config_cores);
    voice_capable = conf.get_bool("voice_capable", voice_capable);
    wide_screen = conf.get_bool("wide_screen", wide_screen);
    ota_certs = conf.get_array("ota_certs", ota_certs);

    config_keyguard_device_secure = conf.get_bool("config.keyguard_device_secure", config_keyguard_device_secure);
    country = conf.get("country", country);
    locale = conf.get("locale", locale);
    time_zone = conf.get("time_zone", time_zone);

    gservices_digest = conf.get(gservices_digest, gservices_digest);

    roaming = conf.get("roaming", roaming);
    cell_operator = conf.get("cell_operator", cell_operator);
    sim_operator = conf.get("sim_operator", sim_operator);
    user_number = conf.get_int("user_number", user_number);
    user_serial_number = conf.get_int("user_serial_number", user_serial_number);

    mac_addr_type = conf.get("mac_addr_type", mac_addr_type);
    if (mac_addr_type == "none")
        mac_addr_type = "";
    mac_addr = conf.get("mac_addr", mac_addr);
    if (mac_addr == "generate") {
        mac_addr = "";
        mac_addr_generate = true;
    }
    meid = conf.get("meid", meid);
    if (meid == "generate") {
        meid = "";
        meid_generate = true;
    }
    serial_number = conf.get("serial_number", serial_number);
    if (serial_number.length() > strlen("generate(") &&
        memcmp(serial_number.c_str(), "generate(", strlen("generate(")) == 0) {
        serial_number = serial_number.substr(strlen("generate("));
        serial_number = serial_number.substr(0, serial_number.find(')'));
        auto iof = serial_number.find(',');

        serial_number_generate = true;
        serial_number_generate_length = std::stoi(serial_number.substr(0, iof));
        serial_number_generate_chars = serial_number.substr(iof + 1);
        serial_number_generate_chars = config::unescape_value(serial_number_generate_chars.substr(
                serial_number_generate_chars.find_first_not_of(" ")));
        serial_number = "";
    } else if (serial_number == "generate") {
        serial_number_generate = true;
        serial_number = "";
    }
}

void device_info::generate_fields() {
    // generate serial number
    if (serial_number_generate) {
        if (generated_serial_number.length() <= 0) {
            for (int i = 0; i < serial_number_generate_length; i++) {
                int j = rand::next_int<int>(0, (int) serial_number_generate_chars.length() - 1);
                generated_serial_number.push_back(serial_number_generate_chars[j]);
            }
        }
        serial_number = generated_serial_number;
    }

    // generate mac address
    if (mac_addr_generate) {
        if (generated_mac_addr.length() <= 0) {
            unsigned char bin_addr[6];
            for (int i = 0; i < 6; i++)
                bin_addr[i] = rand::next_int<unsigned char>((unsigned char) 0, UCHAR_MAX);
            bin_addr[0] &= 0xfe;
            bin_addr[0] |= 0x02;
            std::stringstream ss;
            for (int i = 0; i < 6; i++)
                ss << std::hex << std::setfill('0') << std::setw(2) << (int) bin_addr[i];
            generated_mac_addr = ss.str();
            assert(generated_mac_addr.length() == 12);
        }
        mac_addr = generated_mac_addr;
    }

    // generate meid
    if (meid_generate) {
        if (generated_meid.length() <= 0) {
            generated_meid.resize(15);
            int chksm = 0;
            for (int i = 0; i < 14; i++) {
                int j = rand::next_int<int>(0, 9);
                generated_meid[i] = (char) (j + '0');
                if (j * 2 >= 10)
                    chksm += (j * 2) % 10 + 1;
                else
                    chksm += j * 2;
            }
            generated_meid[14] = (char) ((10 - chksm % 10) + '0');
        }
        meid = generated_meid;
    }

    // generate random logging id
    if (random_logging_id == 0)
        random_logging_id = rand::next_int<long long>(1, LLONG_MAX);
}

void device_info::fill_device_config_proto(proto::gsf::DeviceConfigurationProto& config,
                                           bool feature_add_gles_version_if_zero) const {
    config.set_touchscreen((int) config_touch_screen);
    config.set_keyboard((int) config_keyboard);
    config.set_navigation((int) config_navigation);
    config.set_screenlayout((int) config_screen_layout);
    config.set_hashardkeyboard(config_has_hard_keyboard);
    config.set_hasfivewaynavigation(config_has_five_way_navig);
    config.set_screendensity(config_screen_density);
    config.set_glesversion(config_gles_version);
    for (const auto& e : config_system_shared_libraries)
        config.add_systemsharedlibrary(e);
    for (const auto& e : config_system_features)
        config.add_systemavailablefeature(e.first);
    for (const auto& e : config_native_platforms)
        config.add_nativeplatform(e);
    config.set_screenwidth(config_screen_width);
    config.set_screenheight(config_screen_height);
    for (const auto& e : config_system_supported_locales)
        config.add_systemsupportedlocale(e);
    for (const auto& e : config_gl_extensions)
        config.add_glextension(e);
    config.set_smallestscreenwidthdp(config_smallest_screen_width_dp);
    config.set_lowramdevice(config_low_ram);
    config.set_totalmemorybytes(config_total_ram);
    config.set_maxnumofcpucores(config_cores);
    for (const auto& e : config_system_features) {
        proto::gsf::DeviceConfigurationProto::FeatureWithGLVersion* feature = config.add_newsystemavailablefeature();
        feature->set_name(e.first);
        if (feature_add_gles_version_if_zero || e.second != 0)
            feature->set_glesversion(e.second);
    }
    config.set_screenlayout2((int) 2);
    config.set_keyguarddevicesecure(config_keyguard_device_secure);
}