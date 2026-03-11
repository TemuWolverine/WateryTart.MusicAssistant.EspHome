import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["network"]

CONF_URL = "url"
CONF_TOKEN = "token"

music_assistant_ns = cg.esphome_ns.namespace("music_assistant")
MusicAssistantComponent = music_assistant_ns.class_(
    "MusicAssistantComponent", cg.Component
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(MusicAssistantComponent),
        cv.Required(CONF_URL): cv.string,
        cv.Required(CONF_TOKEN): cv.string,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add(var.set_url(config[CONF_URL]))
    cg.add(var.set_token(config[CONF_TOKEN]))
